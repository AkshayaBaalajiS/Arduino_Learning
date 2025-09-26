FROM ubuntu:22.04
# the below will not work cause the curl is not installed 

#RUN apt update && apt install -y cmake g++ 
# Install dependencies
RUN apt update && apt install -y \
    cmake \
    g++ \
    curl \
    python3 \
    python3-pip

 # Download the latest release (replace version if newer is out)
# RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

# Move it into your PATH
# RUN mv bin/arduino-cli /usr/local/bin/

# RUN arduino-cli core update-index

#additional dependency 
RUN apt-get update && apt-get install -y python3 python3-pip && pip3 install pyserial


# Install Arduino CLI
RUN curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
RUN mv bin/arduino-cli /usr/local/bin/

# Add ESP32 board manager URL
RUN arduino-cli config init
RUN arduino-cli config set board_manager.additional_urls https://dl.espressif.com/dl/package_esp32_index.json

# Update index
RUN arduino-cli core update-index

# Install only stable ESP32 core (lighter, avoids RV32 downloads)
RUN arduino-cli core install esp32:esp32@3.0.2


# the export wont work with RUN cause RUN execute on own shell
# RUN export ARDUINO_HTTP_TIMEOUT=1200

#So use the below 
#ENV sets an environment variable inside the container
ENV  ARDUINO_HTTP_TIMEOUT=12000000000000


WORKDIR /home/5.BlinkCodeWithDocker

COPY . . 

RUN arduino-cli compile --fqbn esp32:esp32:esp32 . 

# the below is the wrong code 
# CMD ["arduino-cli upload -p /dev/ttyUSB0 --fqbn esp32:esp32:esp32 . "]

# The below is the correct way 
CMD ["arduino-cli", "upload", "-p", "/dev/ttyUSB0", "--fqbn", "esp32:esp32:esp32", "."]

