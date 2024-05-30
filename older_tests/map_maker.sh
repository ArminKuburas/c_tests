#!/bin/bash

# Function to generate a random character from the given set
generate_random_character() {
	characters=("0" "1" "C" "E" "P")
	random_index=$((RANDOM % ${#characters[@]}))
	echo "${characters[random_index]}"
}

# Function to generate a map with the specified width and height
generate_map() {
	width=$1
	height=$2
	valid=$3

	# Check if the map dimensions are valid
	if [[ $width -lt 3 || $height -lt 3 ]]; then
		echo "Invalid map dimensions. Minimum width and height should be 3."
		exit 1
	fi

	# Generate the map
	map=""
	for ((i = 0; i < height; i++)); do
		for ((j = 0; j < width; j++)); do
			# Check if the current position is on the border
			if [[ $i -eq 0 || $i -eq $((height - 1)) || $j -eq 0 || $j -eq $((width - 1)) ]]; then
				map+="1"  # Add a wall character
			else
				map+=$(generate_random_character)  # Add a random character
			fi
		done
		map+="\n"  # Add a new line after each row
	done

	# Check if the map should be valid or impossible
	if [[ $valid == "valid" ]]; then
		# Add a valid path to the map
		start_row=$((RANDOM % (height - 2) + 1))
		start_col=$((RANDOM % (width - 2) + 1))
		map_lines=($map)
		map_lines[$start_row]=${map_lines[$start_row]:0:$start_col}"P"${map_lines[$start_row]:$((start_col + 1))}
		map=$(IFS=$'\n'; echo "${map_lines[*]}")
		map=$(echo "$map" | sed "s/C/0/g")  # Replace collectibles with empty spaces
		map=$(echo "$map" | sed "s/E/0/g")  # Replace exit with empty space
	else
		# Add impossible path to the map
		map=$(echo "$map" | sed "s/C/1/g")  # Replace collectibles with walls
		map=$(echo "$map" | sed "s/E/1/g")  # Replace exit with wall
	fi

	echo -e "$map"
}

# Read input from the user
width=$1
height=$2
valid=$3
filename=$4

# Generate the map
map=$(generate_map "$width" "$height" "$valid")

# Save the map to a .ber file
echo "$map" > "$filename.ber"
echo "Map generated and saved as $filename.ber"
