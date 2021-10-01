# Crash Team Racing PSX Decompilation

![build](https://github.com/mkst/ctr/workflows/build/badge.svg)

Proof of concept PSX decompilation of Crash Team Racing `SCUS-94426` using N64 decomp tooling.

## Building

The instructions below assume that you will be using `Ubuntu 20.04`; either natively, via [WSL2](https://docs.microsoft.com/en-us/windows/wsl/install-win10), or via [Docker](https://docs.docker.com/get-docker/).

Please check the [packages.txt](packages.txt) and [requirements.txt](requirements.txt) for the prerequisite Linux and Python packages respectively. You'll also need the `mips-elf` flavour of `binutils`.

**NOTE:** You can take the precompiled binutils binaries from [here](https://github.com/mkst/esa/releases).

### Cloning

Clone the repository; note the `--recursive` flag to fetch submodules at the same time:

```sh
git clone git@github.com:mkst/ctr.git --recursive
```

Navigate into the freshly cloned repo

```sh
cd ctr
```

Copy in `scus_944.26` from the `SCUS-94426` CDROM as `bootloader.dat`.

### Using Docker

Spin up a container using the pre-built, ready-to-go, image:
```sh
docker run --rm -ti -v $(pwd):/ctr ghcr.io/mkst/ctr:latest
```

### Common Steps

**Extract code/data from `bootloader.dat`:**
```sh
make extract
```

**Rebuild as `build/bootloader.dat`:**
```
make
```

## Modifying Code

Once you have an :ok: build, copy it into the `expected/` folder so `asm-differ` can use it as a reference.

```
cp -r build/ expected/
```
