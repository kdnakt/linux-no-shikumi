FROM ubuntu:latest

ENV TZ="Asia/Tokyo"

RUN apt-get update \
    && apt-get install -y tzdata \
    && rm -rf /var/lib/apt/lists/* \
    && echo "${TZ}" > /etc/timezone \
    && rm /etc/localtime \
    && ln -s /usr/share/zoneinfo/Asia/Tokyo /etc/localtime \
    && dpkg-reconfigure -f noninteractive tzdata

RUN sed -i "s@path-exclude=/usr/share/man/*@# path-exclude=/usr/share/man/*@g" /etc/dpkg/dpkg.cfg.d/excludes

RUN apt-get update && \
    apt-get install git binutils build-essential sysstat strace python3 man -y
