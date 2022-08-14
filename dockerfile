FROM debian:10-slim

WORKDIR /app

RUN apt update && \
    apt upgrade --yes && \
    apt install locales --yes && \
    dpkg-reconfigure tzdata

## INSTALL ESSENTIALS
RUN apt-get install --yes \
    build-essential \
    git \ 
    cmake \ 
    curl \
    pkg-config \
    zip \
    unzip \
    libssl-dev \
    openssl \
    tar

## MANAGER DEPENDENCIES
RUN rm -rf /var/lib/apt/lists/*

WORKDIR /app/libraries
RUN git clone https://github.com/Microsoft/vcpkg.git && \
    ./vcpkg/bootstrap-vcpkg.sh && \
    ./vcpkg/vcpkg integrate install

RUN ["bash", "-c", "./vcpkg/vcpkg install poco"]