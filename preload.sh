#!/usr/bin/env bash

set -e

if [ -v LIB_NAME ]
then
    BASE_DIR=/opt/wrap
    LIB_WRAP=${BASE_DIR}/${LIB_NAME}_wrap.so
    test -f ${LIB_WRAP} || (echo "ERROR: cannot find ${LIB_WRAP}" && false)
    export LD_PRELOAD="${LIB_WRAP} /usr/lib/x86_64-linux-gnu/libdl.so"
    echo "Preloaded ${LIB_WRAP}"
fi

# Run initial command line
$*
