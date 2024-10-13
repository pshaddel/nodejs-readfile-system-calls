#!/bin/bash

# Create data directory if it doesn't exist
mkdir -p ./data

# Find and process .js files
for js_file in *.js; do
    if [[ -f "$js_file" ]]; then
        for param in 1 101; do
            strace -o ./data/"${js_file%.js}"_"$param".txt -c node ./"$js_file" "$param"
        done
    fi
done

# Find and process .c files
for c_file in *.c; do
    if [[ -f "$c_file" ]]; then
        # Compile the .c file
        gcc ./"$c_file" -o ./"${c_file%.c}" -luv
        for param in 1 101; do
            strace -o ./data/"${c_file%.c}"_"$param".txt -c ./"${c_file%.c}" "$param"
        done
    fi
done