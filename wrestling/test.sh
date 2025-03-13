#!/bin/bash

# Check if exactly two source files are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <source_file_1.cpp> <source_file_2.cpp>"
    exit 1
fi

# Assign source files to variables
SOURCE1="$1"
SOURCE2="$2"

# Check if the source files exist
if [ ! -f "$SOURCE1" ]; then
    echo "Error: File '$SOURCE1' not found!"
    exit 1
fi

if [ ! -f "$SOURCE2" ]; then
    echo "Error: File '$SOURCE2' not found!"
    exit 1
fi

# Ensure the input directory exists
INPUT_DIR="./in"
if [ ! -d "$INPUT_DIR" ] || [ ! "$(ls -A "$INPUT_DIR")" ]; then
    echo "Error: Directory '$INPUT_DIR' does not exist or is empty!"
    exit 1
fi

# Compile the first source file
echo "Compiling $SOURCE1..."
g++ -o program1 "$SOURCE1" -O2
if [ $? -ne 0 ]; then
    echo "Compilation of $SOURCE1 failed."
    exit 1
fi

# Compile the second source file
echo "Compiling $SOURCE2..."
g++ -o program2 "$SOURCE2" -O2
if [ $? -ne 0 ]; then
    echo "Compilation of $SOURCE2 failed."
    exit 1
fi

# Function to measure execution time of a program
measure_time() {
    local program=$1
    local input_file=$2
    TIME_OUTPUT=$( { /usr/bin/time -f "%e" "$program" "$input_file"; } 2>&1 )
    echo "$TIME_OUTPUT"
}

# Loop through all input files in the ./in/ directory
for input_file in "$INPUT_DIR"/*
do
    if [ ! -f "$input_file" ]; then
        continue  # Skip non-regular files (e.g., directories)
    fi

    echo "Input File: $input_file"

    # Measure execution time of the first program
    echo "Running $SOURCE1 on $input_file..."
    TIME1=$(measure_time ./program1 "$input_file")

    # Measure execution time of the second program
    echo "Running $SOURCE2 on $input_file..."
    TIME2=$(measure_time ./program2 "$input_file")
	echo ""

    # Calculate the difference in execution times
    DIFF_TIME=$(echo "$TIME2 - $TIME1" | bc)

    # Report the results for this input file
    echo "Execution time for $SOURCE1: $TIME1 seconds"
    echo "Execution time for $SOURCE2: $TIME2 seconds"
    echo "Difference in execution time: $DIFF_TIME seconds"
    echo "--------------------------------------------"
done

# Clean up
rm -f program1 program2 out.txt
