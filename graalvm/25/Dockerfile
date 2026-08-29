FROM ubuntu:22.04

ARG TARGETPLATFORM

LABEL author="CSD" maintainer="mail@csd9773.site"

LABEL org.opencontainers.image.source="https://github.com/anhtran1006/pterodactyl-docker"
LABEL org.opencontainers.image.licenses=MIT

ENV LANG='vi_VN.UTF-8' LANGUAGE='vi_VN:vi' LC_ALL='vi_VN.UTF-8' TZ='Asia/Ho_Chi_Minh' DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y curl ca-certificates openssl git tar sqlite3 fontconfig tzdata locales iproute2 gcc libc6-dev \
    && echo "vi_VN.UTF-8 UTF-8" >> /etc/locale.gen \
    && locale-gen vi_VN.UTF-8 \
    && case "${TARGETPLATFORM}" in linux/amd64) ARCH=x64 ;; linux/arm64) ARCH=aarch64 ;; *) echo "Unsupported platform: ${TARGETPLATFORM}" && exit 1 ;; esac \
    && curl -Lfso /tmp/graalvm.tar.gz "https://download.oracle.com/graalvm/25/latest/graalvm-jdk-25_linux-${ARCH}_bin.tar.gz" \
    && mkdir -p /opt/java/graalvm \
    && tar -xf /tmp/graalvm.tar.gz --strip-components=1 -C /opt/java/graalvm \
    && rm -rf /tmp/graalvm.tar.gz /var/lib/apt/lists/*

ENV JAVA_HOME="/opt/java/graalvm" PATH="/opt/java/graalvm/bin:$PATH"

COPY cpu-spoof.c /tmp/cpu-spoof.c
RUN gcc -shared -fPIC -O2 -Wall -Wextra -o /usr/local/lib/libcpu-spoof.so /tmp/cpu-spoof.c -ldl \
    && rm /tmp/cpu-spoof.c \
    && chmod 755 /usr/local/lib/libcpu-spoof.so

RUN useradd -d /home/container -m container

USER container
ENV USER=container HOME=/home/container
WORKDIR /home/container

COPY ./entrypoint.sh /entrypoint.sh
CMD [ "/bin/bash", "/entrypoint.sh" ]