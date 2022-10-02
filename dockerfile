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
    make \
    cmake \ 
    curl \
    pkg-config \
    zip \
    unzip \
    libssl-dev \
    openssl \
    python3 \
    librange-v3-dev \
    ccache \
    zlib1g-dev \
    libjsoncpp-dev \
    uuid-dev \
    tar \
    libtool \
    musl-dev \
    medusa \
     libpq-dev \
     postgresql \
     libc6-dev \
    golang-go

## MANAGER DEPENDENCIES
RUN rm -rf /var/lib/apt/lists/*

WORKDIR /app/libraries
RUN git clone https://github.com/Microsoft/vcpkg.git && \
    ./vcpkg/bootstrap-vcpkg.sh && \
    ./vcpkg/vcpkg integrate install

# ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/app/src/test/

RUN echo '"-DCMAKE_TOOLCHAIN_FILE=/app/libraries/vcpkg/scripts/buildsystems/vcpkg.cmake" > ./vcpkg/CMAKE.txt"'
# CMD [ "bash -c", "./vcpkg/vcpkg install" ]