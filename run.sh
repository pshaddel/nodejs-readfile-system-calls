echo "Running strace on file read operations"
echo "--------------------------------------"
echo "C using libuv"
strace -c ./file_read_uv
echo "--------------------------------------"
echo "C"
strace -c ./file_read
echo "--------------------------------------"
echo "Node.js Callback"
strace -c node ./read_file_callback.js
echo "--------------------------------------"
echo "Node.js Sync"
strace -c node ./read_file_sync.js
echo "--------------------------------------"
echo "Node.js Promise"
strace -c node ./read_file_promise.js