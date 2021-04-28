# manymaths

A Docker image to play with multiple libmaths implementations

Example usage:
```
docker run -e LIB_NAME="musl-v1.1.24-1" --rm manymaths ls
```

Supported libraries and versions:
* `glibc-v2.31`
* `intel-v2021.2.0`
* `mpfr`
* `musl-v1.1.24-1`
* `openlibm-v0.7.0`
* `openlibm-v0.7.5`