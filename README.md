# Crash Team Racing PSX Decompilation

Proof of concept PSX decompilation using N64 decomp tooling.

## Building

Copy in `scus_944.26` as `bootloader.dat`.

```sh
git clone --recursive
```

**Extract code/data:**
```sh
make extract
```

**Rebuild:**
```
make
```

## Modifying Code

Once you have an :OK: build, copy it into the `expected/` folder so `asm-differ` can use it as a reference.

```
cp -r build/ expected/
```
