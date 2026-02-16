#!/bin/bash

OUTPUT="lib/HiCPPM.h"

# Create output directory if it doesn't exist
mkdir -p lib

# Create header guard
echo "#ifndef HICPPM_H" > $OUTPUT
echo "#define HICPPM_H" >> $OUTPUT
echo "" >> $OUTPUT

# Add any necessary includes first
echo "// Standard includes" >> $OUTPUT
echo "#include <vector>" >> $OUTPUT
echo "#include <string>" >> $OUTPUT
echo "" >> $OUTPUT

# Loop through all .h files
for file in src/*.h; do
    if [ "$file" != "$OUTPUT" ] && [ -f "$file" ]; then
        echo "// From $file" >> $OUTPUT
        
        # Extract includes
        grep -E "^#include" "$file" >> $OUTPUT
        
        # Extract function declarations, class/struct definitions
        # This captures multi-line and handles more cases
        grep -E "^\s*(int|void|double|float|char|bool|class|struct|namespace|template|typedef|using).*" "$file" | \
        grep -v "^#ifndef\|^#define\|^#endif" >> $OUTPUT
        
        echo "" >> $OUTPUT
    fi
done

# Close header guard
echo "#endif // HICPPM_H" >> $OUTPUT

echo "Combined header created: $OUTPUT"