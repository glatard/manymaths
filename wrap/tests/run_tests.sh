#!/usr/bin/env bash

LIBS="mpfr glibc-v2.31 intel-v2021.2.0 musl-v1.1.24-1 openlibm-v0.7.0 openlibm-v0.7.5"

for LIB in ${LIBS}
do
    echo "Testing ${LIB}"
    docker run -e LIB_NAME=${LIB} -v $PWD:$PWD -w $PWD --rm manymaths ./test > test-${LIB}.txt
done