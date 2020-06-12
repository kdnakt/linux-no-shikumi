FROM ubuntu:latest

RUN apt-get update && \
    apt-get install git binutils build-essential sysstat strace python3 -y
