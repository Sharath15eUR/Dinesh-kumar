#!/bin/bash

# Check if input is given
if [ -z "$1" ]; then
    echo "Usage: $0 <input_file>"
    exit 1
fi 

# Assign variables
INPUT_FILE="$1"
OUTPUT_FILE="/media/sf_SHARED/LINUX/MODULE_04/output.txt"

# Clear the output file
> "$OUTPUT_FILE"

# Extract required parameters and save to output file
grep -E '"frame.time"|"wlan.fc.type"|"wlan.fc.subtype"' "$INPUT_FILE" | sed 's/^\s*//' > "$OUTPUT_FILE"

echo "Extraction completed. Output saved in '$OUTPUT_FILE'"
