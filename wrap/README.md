# wrap

A wrapper to redirect math calls to a customizable library.

* `wrap.c`: library is defined in variable LIB_PATH
* `wrap-mpfr.c`: library is GNU MPFR

## Compilation

### All libraries except MPFR
Set LIB_PATH to the target library path, LIB_NAME to the target library name:
`make wrap LIB_PATH=/opt/openlibm-v0.7.5/libopenlibm.so.3 LIB_NAME=openlibm-v0.7.5`
Produces `$${LIB_NAME}_wrap.so`.

### MPFR
`make wrap-mpfr`


## Usage

Wrapped functions are injected in the application through `LD_PRELOAD`:
`export LD_PRELOAD="${LIB_NAME}_wrap /usr/lib/x86_64-linux-gnu/libdl.so"`

