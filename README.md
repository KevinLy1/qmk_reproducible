# QMK & Vial Frozen Build Environments

This repository provides frozen, reproducible Docker environments for building both QMK and Vial-QMK firmware. QMK and Vial evolve constantly, and breaking changes happen.
These snapshots ensure that even years from now, you can still compile firmware exactly as you used to.

The goal is simple: if in future you get lazy or busy, everything will still work.

QMK Repository: https://github.com/qmk/qmk_firmware  
Vial-QMK Repository: https://github.com/vial-kb/vial-qmk

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

This project exists for one reason: if one wants to be able to compile the current keyboard firmwares in 5, 10, or 20 years without fighting the tools.

Snapshots are:

- archived
- versioned
- reproducible
- portable

## Snapshot references for this branch

### QMK Firmware
QMK Firmware tag 0.33.7: https://github.com/qmk/qmk_firmware/releases/tag/0.33.7  
or my fork: https://github.com/KevinLy1/qmk_firmware/tree/20260613

### Vial (QMK fork)

`vial` branch of Vial QMK (as of June 13, 2026): https://github.com/vial-kb/vial-qmk  
or my fork: https://github.com/KevinLy1/vial-qmk/tree/20260613

### Vial GUI

Compatible with vial-gui v0.7.5: https://github.com/vial-kb/vial-gui/releases/tag/v0.7.5  
or: https://github.com/KevinLy1/vial-gui/releases/tag/v0.7.5

### VIA Web App
As of June 13th, 2026, compatible with the VIA web app on https://usevia.app/ (https://github.com/the-via/app)  
Forked branch: https://github.com/KevinLy1/via-app/tree/20260613


### VIA-Desktop (Offline)

Compatible with offline VIA: https://github.com/cebby2420/via-desktop/releases/tag/v2026.5.18  
or: https://github.com/KevinLy1/via-desktop/releases/tag/v2026.5.18

## Additional reference

Old firmware releases: https://github.com/KevinLy1/qmk_firmware/releases

## Note for small EEPROM boards and Vial
Some boards use the ATmega32U4 chip and have a small EEPROM. Firmwares for Vial-QMK were not port for these boards, as it usually requires sacrificing many other features.
Using VIA, plain QMK, or offline VIA is an option.