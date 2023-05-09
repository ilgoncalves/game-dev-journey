#!/bin/bash

# Get the name of the C++ source file from the command-line argument
if [ -z "$1" ]; then
    echo "Please specify a C++ source file."
    exit 1
fi

filename="$1"
if [ ! -f "$filename" ]; then
    echo "File not found: $filename"
    exit 1
fi

# Get the directory where the script is located
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Change to the directory where the C++ source file is located
cd "$( dirname "$filename" )"

# Compile and run the C++ program
program_name="${filename%.*}"
g++ -o "$program_name".out "$filename"
"./$program_name".out

# Change back to the original directory
cd "$script_dir"