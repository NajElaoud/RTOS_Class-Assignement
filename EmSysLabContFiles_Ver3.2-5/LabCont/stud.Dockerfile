FROM rootsblabimg:3.2-5
#MAINTAINER Sadok BAZINE "sbazine.ens@gmail.com"
LABEL maintainer="SADOK BAZINE <sbazine.ens@gmail.com>"

### Non Root User ###
ARG USER_NAME
ARG GROUP_NAME=sblab
ARG USER_ID=1000
ARG GROUP_ID=$USER_ID

# Create non-root user with sudo
RUN groupadd $GROUP_NAME && \
    useradd -m -g $GROUP_NAME $USER_NAME && \
    echo "$USER_NAME:$USER_NAME" | chpasswd && \
    adduser $USER_NAME sudo && \
    adduser $USER_NAME dialout

RUN cp /labrepo/config/dot.zshrc /home/$USER_NAME/.zshrc && \
    cp /labrepo/config/dot.bashrc /home/$USER_NAME/.bashrc

USER $USER_NAME

# Onstall ESP32 and STM32 platforms
RUN /opt/py-venv/bin/platformio platform install \
    espressif32 \
    ststm32

WORKDIR /home/$USER_NAME/WorkDir
SHELL [ "/bin/zsh", "-c"]
ENTRYPOINT [ "/bin/zsh"]
