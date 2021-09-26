FROM ubuntu:20.04 as binutils

RUN apt-get update && apt-get install -y wget build-essential

ARG BINUTILS_VERSION=2.36.1
ARG BINUTILS_SHA1SUM=968cddc17354142ab7d60b93d7f169ec8373a9f4

RUN wget https://ftp.gnu.org/gnu/binutils/binutils-${BINUTILS_VERSION}.tar.bz2 && \
  echo "${BINUTILS_SHA1SUM}  binutils-${BINUTILS_VERSION}.tar.bz2" | sha1sum --check && \
  tar xvjf binutils-${BINUTILS_VERSION}.tar.bz2 && \
  cd /binutils-${BINUTILS_VERSION} && \
  ./configure --target=mips-elf && \
  make --jobs 4 && \
  make install


FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY /packages.txt /

RUN dpkg --add-architecture i386 && apt-get update && \
  apt-get install -y \
    -o APT::Immediate-Configure=false $(cat /packages.txt) && \
  rm -rf /var/lib/apt/lists/*

COPY requirements.txt /

RUN python3 -m pip install -r /requirements.txt --no-cache-dir

COPY --from=binutils /usr/local/bin/mips-elf-* /usr/local/bin/

COPY .bash_aliases /root/.bash_aliases

RUN winecfg

RUN mkdir /ctr
WORKDIR /ctr
