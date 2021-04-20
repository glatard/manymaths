#!/usr/bin/env bash

set -e

if [ -v LIB_NAME ]
then
    BASE_DIR=/opt/wrap
    LIB_PATH=${BASE_DIR}/${LIB_NAME}_wrap.so
    test -f ${LIB_PATH} || (echo "ERROR: cannot find ${LIB_PATH}" && false)
    export LD_PRELOAD=${LIB_PATH}
    echo "Preloaded ${LIB_PATH}"
fi

# Run initial command line
$*
