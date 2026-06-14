FROM debian:bookworm-slim

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install --no-install-recommends -y \
    git \
    make \
    python3 \
    python3-pip \
    gcc \
    build-essential \
    ca-certificates \
    gcc-arm-none-eabi \
    binutils-arm-none-eabi \
    libnewlib-arm-none-eabi \
    gcc-avr \
    binutils-avr \
    avr-libc \
    dfu-util \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --no-cache-dir qmk --break-system-packages

WORKDIR /qmk

RUN git clone https://github.com/qmk/qmk_firmware . && git submodule update --init --recursive

CMD ["tail", "-f", "/dev/null"]
