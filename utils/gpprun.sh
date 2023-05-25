#!/bin/bash

# Get the name of the C++ source files from the command-line arguments
if [ -z "$1" ]; then
    echo "Please specify at least one C++ source file."
    exit 1
fi

# Check all files exist
for filename in "$@"; do
    if [ ! -f "$filename" ]; then
        echo "File not found: $filename"
        exit 1
    fi
done

# Get the directory where the script is located
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Change to the directory where the first C++ source file is located
cd "$( dirname "$1" )"

# Compile and run the C++ program
# We use the name of the first source file to derive the program name
program_name="${1%.*}"
g++ -o "$program_name".out "$@"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi
"./$program_name".out

# Change back to the original directory
cd "$script_dir"