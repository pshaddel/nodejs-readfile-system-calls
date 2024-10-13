#!/bin/bash

# Create data directory if it doesn't exist
mkdir -p ./data

# Find and process .js files in src directory
for js_file in ./src/*.js; do
    if [[ -f "$js_file" ]]; then
        for param in 1 101; do
            strace -o ./data/"$(basename "${js_file%.js}")"_"$param".txt -c node "$js_file" "$param"
            node convert.js ./data/"$(basename "${js_file%.js}")"_"$param".txt ./data/"$(basename "${js_file%.js}")"_"$param"_converted.json
        done
    fi
done

# Find and process .c files in src directory
for c_file in ./src/*.c; do
    if [[ -f "$c_file" ]]; then
        # Compile the .c file
        gcc "$c_file" -o ./src/"$(basename "${c_file%.c}")" -luv
        for param in 1 101; do
            strace -o ./data/"$(basename "${c_file%.c}")"_"$param".txt -c ./src/"$(basename "${c_file%.c}")" "$param"
            node convert.js ./data/"$(basename "${c_file%.c}")"_"$param".txt ./data/"$(basename "${c_file%.c}")"_"$param"_converted.json
        done
    fi
done
done