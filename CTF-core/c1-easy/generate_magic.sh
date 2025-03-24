#!/bin/bash
# Define the magic word
MAGIC_WORD="Azaroth"

# Generate a random number between 5 and 15 for the encoding iterations
ENCODE_COUNT=$((RANDOM % 11 + 5))

# Perform Base64 encoding the specified number of times
ENCODED_TEXT="$MAGIC_WORD"
for ((i = 1; i <= ENCODE_COUNT; i++)); do
  ENCODED_TEXT=$(echo -n "$ENCODED_TEXT" | base64)
done

# Write the encoded text to cheese_lock.txt in the home directory
echo "$ENCODED_TEXT" >/home/ctfuser/cheese_lock.txt

# Write a riddle to riddle.txt
echo "The word has been whispered by the cave's echoes exactly $ENCODE_COUNT times. Solve for $ENCODE_COUNT to reveal its true form." >/home/ctfuser/riddle.txt

# Optionally, output a message (or not)
echo "Challenge files generated."

# Delete this script from the container
rm -- "$0"
