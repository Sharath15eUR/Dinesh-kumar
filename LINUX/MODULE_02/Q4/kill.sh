#!/bin/bash

# List the top 10 processes by memory usage and save to list.txt
ps -eo pid,%mem,cmd --sort=-%mem | head -n 11 > list.txt

# Find the process with the highest memory usage
highest_mem_pid=$(ps -eo pid --sort=-%mem | head -n 2 | tail -n 1)

# Check if a process ID was found
if [[ -n "$highest_mem_pid" ]]; then
    echo "Terminating process with PID: $highest_mem_pid"
    # Terminate the process
    kill -9 "$highest_mem_pid"
    echo "Process $highest_mem_pid terminated."
else
    echo "No process found with high memory usage."
fi
