# NodeJS Read File System Calls

Compile and Run `file_read.c`

```bash
gcc ./file_read_uv.c -o file_read
file_read
```

Compile and Run `file_read_uv.c`, you have to first install `libuv`(use this [link](https://github.com/libuv/libuv))
```bash
gcc ./file_read_uv.c -o file_read_uv -luv
file_read_uv
```

#### How to Trace
Use `strace`, it works only on Linux
```bash
# For Debian-based distributions like Ubuntu
sudo apt-get install strace

# For RPM-based distributions like CentOS
sudo yum install strace
```

Tracing
```bash
strace -c ./file_read
strace -c node ./read_file_callback.js
```
