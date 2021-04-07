FROM ubuntu:focal
# Comes with glibc 2.31

# Install musl and libopenlibm3
RUN apt update -y && apt install -y musl libopenlibm3 wget gnupg

# root@c7a6f9f5c196:/lib/x86_64-linux-musl# dpkg --listfiles libopenlibm3

# Install tzdata non interactively (forces UTC time zone)
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata

# Install Intel libraries
# See https://software.intel.com/content/www/us/en/develop/documentation/installation-guide-for-intel-oneapi-toolkits-linux/top/installation/install-using-package-managers/apt.html
RUN (cd /tmp && wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB\
     && apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB && rm GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB\
     && echo "deb https://apt.repos.intel.com/oneapi all main" | tee /etc/apt/sources.list.d/oneAPI.list\
     && DEBIAN_FRONTEND=noninteractive apt install -y intel-mkl)


