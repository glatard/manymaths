# manymaths

A Docker image to play with multiple libmaths implementations

Example:
```
docker run -e LIB_NAME="musl-v1.1.24-1" --rm manymaths ls
```

Supported libraries and versions:
* `glibc-v2.31`
* `musl-v1.1.24-1`
* `openlibm-v0.7.0`
* `openlibm-v0.7.5`
* `intel-v2021.2.0`

## Experimentation with HCP pipelines

Sanity checks:
- Preloading of openlibm and openlibm wrapper give same results
- Regular glibc execution and glibc wrapper give same results
- `wrap/test.c` to be expanded