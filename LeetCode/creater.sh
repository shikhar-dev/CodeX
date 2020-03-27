#!/bin/bash
# Taking question url as input
FILENAME="$(printf $1 | cut -d'/' -f5)"
echo "// Problem URL: $1" > "$FILENAME.cpp"
