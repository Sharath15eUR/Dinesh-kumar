#!/bin/bash

# Function to print usage and exit
usage() {
    echo "Usage: $0 <source_directory> <backup_directory> <file_extension>"
    exit 1
}

# Check for the correct number of arguments
if [ "$#" -ne 3 ]; then
    usage
fi

SOURCE_DIR="$1"
BACKUP_DIR="$2"
FILE_EXT="$3"

# Check if source directory exists
if [ ! -d "$SOURCE_DIR" ]; then
    echo "Source directory does not exist."
    exit 1
fi

# Check if backup directory exists, create if not
if [ ! -d "$BACKUP_DIR" ]; then
    mkdir -p "$BACKUP_DIR" || { echo "Failed to create backup directory."; exit 1; }
fi

# Use globbing to find files with the specified extension
FILES=("$SOURCE_DIR"/*"$FILE_EXT")

# Check if files matching the extension exist in the source directory
if [ "${#FILES[@]}" -eq 0 ]; then
    echo "No files matching the extension found in the source directory."
    exit 1
fi

# Export BACKUP_COUNT environment variable
export BACKUP_COUNT=0

# Print the names and sizes of files to be backed up
echo "Files to be backed up:"
for FILE in "${FILES[@]}"; {
    echo "$(basename "$FILE") - $(stat -c%s "$FILE") bytes"
}

# Backup files
for FILE in "${FILES[@]}"; do
    BASENAME=$(basename "$FILE")
    DEST_FILE="$BACKUP_DIR/$BASENAME"

    # Check if the file already exists in the backup directory
    if [ -f "$DEST_FILE" ]; then
        # Compare timestamps and overwrite if the source file is newer
        if [ "$FILE" -nt "$DEST_FILE" ]; then
            cp "$FILE" "$DEST_FILE"
            ((BACKUP_COUNT++))
        fi
    else
        cp "$FILE" "$DEST_FILE"
        ((BACKUP_COUNT++))
    fi
done

# Generate summary report
TOTAL_SIZE=$(du -sh "$BACKUP_DIR" | cut -f1)
REPORT_FILE="$BACKUP_DIR/backup_report.log"

echo "Backup Report" > "$REPORT_FILE"
echo "-------------" >> "$REPORT_FILE"
echo "Total files processed: $BACKUP_COUNT" >> "$REPORT_FILE"
echo "Total size of files backed up: $TOTAL_SIZE" >> "$REPORT_FILE"
echo "Backup directory: $BACKUP_DIR" >> "$REPORT_FILE"

# Print report to the console
cat "$REPORT_FILE"

echo "Backup completed successfully."

exit 0
