#!/bin/bash

# Identify the process with the highest memory usage
highest_mem_pid=$(ps aux --sort=-%mem | awk 'NR==2{print $2}')

# Check if a process ID was found
if [ -z "$highest_mem_pid" ]; then
  echo "No process found."
  exit 1
fi

echo "Process with highest memory usage: $highest_mem_pid"

# Terminate the process with the highest memory usage
kill -9 $highest_mem_pid

echo "Process $highest_mem_pid has been terminated."

