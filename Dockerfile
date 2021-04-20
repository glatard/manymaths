FROM ubuntu:focal
# Comes with glibc 2.31

# Install musl and libopenlibm3
RUN apt update -y && apt install -y musl wget gnupg 

# Install openlibm3
RUN apt install -y git make gcc &&\
    ( cd /opt && \
    git clone -b v0.7.5 https://github.com/JuliaMath/openlibm.git openlibm-v0.7.5 && (cd openlibm-v0.7.5 && make) &&\
    git clone -b v0.7.0 https://github.com/JuliaMath/openlibm.git openlibm-v0.7.0 && (cd openlibm-v0.7.0 && make))
# root@c7a6f9f5c196:/lib/x86_64-linux-musl# dpkg --listfiles libopenlibm3

ADD wrap /opt/wrap
RUN (cd /opt/wrap && make wrap LIB_PATH=/opt/opemlibm-v0.7.0/libopenlibm.so LIB_NAME=openlibm-v0.7.0 &&\
     make wrap LIB_PATH=/opt/opemlibm-v0.7.5/libopenlibm.so LIB_NAME=openlibm-v0.7.5 &&\
     MUSL_VERSION=$(dpkg -s musl | grep Version | awk '{print $NF}') && make wrap LIB_PATH=/lib/x86_64-linux-musl/libc.so LIB_NAME=musl-v${MUSL_VERSION} &&\
     GLIBC_VERSION=$(/lib/x86_64-linux-gnu/libc.so.6 | grep "stable release version" | awk '{print $NF}') && GLIBC_VERSION=${GLIBC_VERSION%.} && make wrap LIB_PATH=/lib/x86_64-linux-gnu/libc.so.6 LIB_NAME=glibc-v${GLIBC_VERSION})

# # Install tzdata non interactively (forces UTC time zone)
# RUN DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends tzdata

# # Install Intel libraries
# # See https://software.intel.com/content/www/us/en/develop/documentation/installation-guide-for-intel-oneapi-toolkits-linux/top/installation/install-using-package-managers/apt.html
# RUN (cd /tmp && wget https://apt.repos.intel.com/intel-gpg-keys/GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB\
#      && apt-key add GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB && rm GPG-PUB-KEY-INTEL-SW-PRODUCTS.PUB\
#      && echo "deb https://apt.repos.intel.com/oneapi all main" | tee /etc/apt/sources.list.d/oneAPI.list\
#      && apt update -y && DEBIAN_FRONTEND=noninteractive apt install -y intel-basekit)

ADD preload.sh /bin/preload.sh

ENTRYPOINT [ "/bin/preload.sh" ]


