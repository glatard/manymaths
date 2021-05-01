#!/usr/bin/env bash

DATA_DIR=$HOME/data/manymaths
#LIBS="glibc-v2.31 mpfr musl-v1.1.24-1 openlibm-v0.7.0 openlibm-v0.7.5 intel-v2021.2.0"
LIBS="mpfr"

for LIB in ${LIBS}
do
    # Cleanup data dir
    \rm -Rf ${DATA_DIR}/${LIB}
    cp -Rf ${DATA_DIR}/orig ${DATA_DIR}/${LIB}
    # Write command to be executed in container
    \rm -f ${DATA_DIR}/run-${LIB}.sh

mkdir -p ${DATA_DIR}/run-${LIB}_log
(cat <<SCRIPT
    #!/usr/bin/env bash
    HOME=/usr/local/src PreFreeSurferPipelineBatch.sh --StudyFolder=${DATA_DIR}/${LIB} --Subject=101309 --runlocal
SCRIPT
) > ${DATA_DIR}/run-${LIB}.sh
    chmod 755 ${DATA_DIR}/run-${LIB}.sh
    # Split the log files in chunks of 100M lines and compress them
    docker run --rm -e LIB_NAME="${LIB}" -v ${DATA_DIR}:${DATA_DIR} -w ${DATA_DIR} --log-driver local --log-opt max-size=10m --log-opt max-file=3\
                       pfs-manymaths ${DATA_DIR}/run-${LIB}.sh 2>&1 |  split -l 100000000 --filter 'bzip2 > "$FILE.bz2"' - ${DATA_DIR}/run-${LIB}_log/log_
done
