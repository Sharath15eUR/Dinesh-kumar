#!/bin/bash

input_file="input_mod.txt"
output_file="output.txt"

# Clear the output file
> "$output_file"

# Read input file line by line
while IFS= read -r line; do
    # Extract parameters using grep and regex
    frame_time=$(echo "$line" | grep -oP '(?<=frame.time": ")[^"]*')
    wlan_fc_type=$(echo "$line" | grep -oP '(?<=wlan.fc.type": ")[^"]*')
    wlan_fc_subtype=$(echo "$line" | grep -oP '(?<=wlan.fc.subtype": ")[^"]*')

    # If all values are found, write to output file
    if [[ -n "$frame_time" && -n "$wlan_fc_type" && -n "$wlan_fc_subtype" ]]; then
        echo "\"frame.time\": \"$frame_time\",\"wlan.fc.type\": \"$wlan_fc_type\",\"wlan.fc.subtype\": \"$wlan_fc_subtype\"" >> "$output_file"
    fi
done < "$input_file"

echo "Extraction completed. Check $output_file."
