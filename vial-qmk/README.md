## Using the Frozen Image

In normal usage, you do not rebuild the image.

Download the release file `vial-qmk_20260613.tar` and place it in this directory.

Open a terminal in this folder and load the frozen snapshot into Docker:

    docker load -i vial-qmk_20260613.tar

Start the environment:

    docker compose up -d
    docker compose exec vial bash

## Project Structure

Two folders are available on the host:

- keyboards — place your custom keyboards here
- output — compiled firmware files will appear here

Inside the container, these map to:

    /vial/keyboards
    /vial/output

The full Vial-QMK source tree remains inside the image and is never overwritten.

## Compile a Firmware

Inside the container:

    cd /vial

Then:

    qmk compile -kb <keyboard> -km <keymap>

Example:
    
    make keygem/kg60ansiso:vial

The firmware will be generated in:

    /vial

Copy it to the shared output folder:

    cp /vial/*.bin /vial/output/ 2>/dev/null || true
    cp /vial/*.hex /vial/output/ 2>/dev/null || true

## Recover Firmware

Your compiled .bin or .hex files will be available in the `output` folder.

## (Optional) Rebuilding the Frozen Image

This section is provided for reference only.  
In normal usage, you do not need to rebuild the image unless you want to create a new snapshot.  
That is the purpose of the Dockerfile.

Below is an example for a snapshot dated June 13th, 2026:

    docker build --no-cache -t vial-qmk:20260613 .
    docker save -o vial-qmk_20260613.tar vial-qmk:20260613

Update the docker-compose.yml file to match the new tag.  
You can then archive or distribute the .tar file for long‑term reproducibility.
