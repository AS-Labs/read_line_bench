#!/bin/bash

FILE="data.txt"

if [ ! -f "$FILE" ]; then
    echo "Error: File '$FILE' not found."
    exit 1
fi

line_count=0
byte_count=0

while IFS= read -r line; do
    ((line_count++))
    byte_count=$((byte_count + ${#line}))
done < "$FILE"

echo "$line_count lines, $byte_count bytes"

