#!/bin/bash

# Function to display help menu using a here document
display_help() {
    cat <<EOF
Usage: $0 [options]
Options:
    -d <directory>  Directory to search.
    -k <keyword>    Keyword to search.
    -f <file>       File to search directly.
    --help          Display this help menu.
Example usage:
    $0 -d logs -k error
    $0 -f script.sh -k TODO
    $0 --help
EOF
}

# Recursive function to search for files containing a specific keyword
search_files_recursive() {
    local dir="$1"
    local keyword="$2"
    for file in "$dir"/*; do
        if [ -d "$file" ]; then
            search_files_recursive "$file" "$keyword"
        elif [ -f "$file" ]; then
            if grep -q "$keyword" "$file"; then
                echo "Found keyword in file: $file"
            fi
        fi
    done
}

# Function to handle errors and log them
log_error() {
    local message="$1"
    echo "Error: $message" | tee -a errors.log
    exit 1
}

# Validate inputs using regular expressions
validate_inputs() {
    if [ -n "$file" ] && [ ! -f "$file" ]; then
        log_error "File $file does not exist."
    fi

    if [[ ! "$keyword" =~ ^[a-zA-Z0-9_]+$ ]]; then
        log_error "Invalid keyword: $keyword"
    fi
}

# Initialize variables
directory=""
keyword=""
file=""

# Parse command-line arguments using getopts
while getopts "d:k:f:-:" opt; do
    case $opt in
        d) directory="$OPTARG" ;;
        k) keyword="$OPTARG" ;;
        f) file="$OPTARG" ;;
        -) case "$OPTARG" in
               help) display_help; exit 0 ;;
               *) log_error "Invalid option: --$OPTARG" ;;
           esac ;;
        \?) log_error "Invalid option: -$OPTARG" ;;
    esac
done

shift $((OPTIND - 1))

# Validate inputs
if [ -z "$directory" ] && [ -z "$file" ]; then
    log_error "Either a directory or a file must be specified."
fi

if [ -z "$keyword" ]; then
    log_error "Keyword must be specified."
fi

validate_inputs

# Perform search
if [ -n "$directory" ]; then
    if [ ! -d "$directory" ]; then
        log_error "Directory $directory does not exist."
    fi
    search_files_recursive "$directory" "$keyword"
elif [ -n "$file" ]; then
    if grep -q "$keyword" <<< "$(cat "$file")"; then
        echo "Found keyword in file: $file"
    else
        echo "Keyword not found in file: $file"
    fi
fi

# Use special parameters for meaningful feedback
echo "Script name: $0"
echo "Number of arguments: $#"
echo "Exit status of last command: $?"
echo "All arguments: $@"
