#!/usr/bin/env bash

DATA_DIR=$HOME/data/manymaths
LIBS="glibc-v2.31 musl-v1.1.24-1 openlibm-v0.7.0 openlibm-v0.7.5 intel-v2021.2.0"

for LIB in ${LIBS}
do
    # Cleanup data dir
    \rm -Rf ${DATA_DIR}/${LIB}
    cp -Rf ${DATA_DIR}/orig ${DATA_DIR}/${LIB}
    # Write command to be executed in container
    \rm -f ${DATA_DIR}/run-${LIB}.sh

(cat <<SCRIPT
    #!/usr/bin/env bash
    HOME=/usr/local/src PreFreeSurferPipelineBatch.sh --StudyFolder=${DATA_DIR}/${LIB} --Subject=101309 --runlocal
SCRIPT
) > ${DATA_DIR}/run-${LIB}.sh
    chmod 755 ${DATA_DIR}/run-${LIB}.sh
    docker run --rm -e LIB_NAME="${LIB}" -v ${DATA_DIR}:${DATA_DIR} -w ${DATA_DIR}\
                       pfs-manymaths ${DATA_DIR}/run-${LIB}.sh &>${DATA_DIR}/run-${LIB}.log
done
