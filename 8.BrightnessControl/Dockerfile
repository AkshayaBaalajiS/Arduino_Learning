FROM ubuntu:22.04

# Install dependencies
RUN apt update && apt install -y \
    cmake \
    g++ \
    curl \
    python3 \
    python3-pip


RUN apt-get update && apt-get install -y python3 python3-pip && pip3 install pyserial


RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
RUN mv bin/arduino-cli /usr/local/bin/

RUN arduino-cli config init
RUN arduino-cli config set board_manager.additional_urls https://dl.espressif.com/dl/package_esp32_index.json

RUN arduino-cli core update-index

RUN arduino-cli core install esp32:esp32@2.0.14

ENV  ARDUINO_HTTP_TIMEOUT=12000000000000

WORKDIR /home/8.BrightnessControl

COPY . . 

RUN arduino-cli compile --fqbn esp32:esp32:esp32 .

CMD ["arduino-cli", "upload", "-p", "/dev/ttyUSB0", "--fqbn", "esp32:esp32:esp32", "."]

