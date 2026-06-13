# QMK & Vial Frozen Build Environments

This repository provides frozen, reproducible Docker environments for building both QMK and Vial-QMK firmware. QMK and Vial evolve constantly, and breaking changes happen.
These snapshots ensure that even years from now, you can still compile firmware exactly as you used to.

The goal is simple: if in future you get lazy or busy, everything will still work.

## Why Freeze QMK and Vial?

Because QMK and Vial move fast:

- toolchains change
- dependencies break
- keyboards get refactored
- features get renamed
- build systems evolve

If you return to a keyboard project after months or years, you may find that it no longer compiles on the latest QMK or Vial.

By freezing snapshots inside Docker images, you get:

- reproducible builds
- no dependency issues
- no need to reinstall toolchains
- guaranteed compatibility with old keymaps
- a stable environment you can archive forever

Load the image, compile, done.

## What This Repository Contains

- A frozen QMK build environment
- A frozen Vial-QMK build environment
- Dockerfiles used to generate snapshots
- Instructions for loading and using the snapshots
- A simple workflow for compiling firmware reliably

## Using the Snapshots

Read the README.md in qmk and vial-qmk folders.

Use whichever one works best for your keyboard.

## Long-Term Philosophy

This project exists for one reason:

If one wants to be able to compile my keyboards in 5, 10, or 20 years without fighting the tools.

Snapshots are:

- archived
- versioned
- reproducible
- portable
