import sys
import os
import struct
import re
import argparse

from pathlib import Path

def main(bigfile, mapfile, outdir="data"):
    filepaths = {}

    for line in mapfile.readlines():
        # e.g. "579=credits\joedance\data.vrm"
        if match := re.match(r"^(\d+) *= *([A-z0-9_.\\]+)", line):
            idx = int(match.group(1))
            filepath = Path(match.group(2).replace("\\", "/"))  # surely there is a better approach
            filepaths[idx] = filepath

    print(f"Found {len(filepaths)} mappings in {mapfile.name}")

    data = bigfile.read()
    file_count, = struct.unpack("<i", data[4:8])
    file_offset = 8

    size_factor = 0x800  # so says https://forum.xentax.com/viewtopic.php?f=10&t=11806

    for i in range(file_count):
        o, l, t = struct.unpack("<IHH", data[file_offset+i*8:file_offset+i*8 + 4+2+2])
        filepath = outdir / filepaths.get(i, Path(f"unnamed_{i:3}.bin"))
        contents = data[o*size_factor:o*size_factor+l]
        if not os.path.isfile(filepath):
            # make directories
            filepath.parent.mkdir(parents=True, exist_ok=True)

            with open(filepath, "wb") as f:
                f.write(contents)
                print(f"Wrote {len(contents)} to {filepath}...")

    print(f"Processed {file_count} files in {bigfile.name}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("bigfile", help="CTR .big file to process", type=argparse.FileType("rb"))
    parser.add_argument("filepaths", help=".txt file containing filenames", type=argparse.FileType("r"))
    parser.add_argument("--outdir", help="Directory to dump files into", default="data")
    args = parser.parse_args()

    main(args.bigfile, args.filepaths, args.outdir)
