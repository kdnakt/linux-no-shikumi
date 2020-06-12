FROM ubuntu:latest

RUN sed -i "s@path-exclude=/usr/share/man/*@# path-exclude=/usr/share/man/*@g" /etc/dpkg/dpkg.cfg.d/excludes

RUN apt-get update && \
    apt-get install git binutils build-essential sysstat strace python3 man manpages-dev -y
