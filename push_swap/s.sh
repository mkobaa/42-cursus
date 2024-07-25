#!/bin/bash

# Maximum range for generating numbers
max=5

# Function to generate random combinations of numbers
generate_combination() {
  local n=$1
  seq 0 99 | sort -R | head -n $n | tr '\n' ' ' | sed 's/ $//'
}

# Initialize a counter
total_tests=0

# Loop through different combination lengths (from 3 to 50)
for num_count in {3..50}; do
  echo "Checking combinations of $num_count numbers..."

  # Loop to generate combinations and check them
  for ((i = 0; i < $max; i++)); do
    # Increment the counter
    total_tests=$((total_tests + 1))

    # Generate a random combination of num_count numbers
    arg=$(generate_combination $num_count)
    
    # Run the push_swap script and check with checker_mac
    result=$(./push_swap $arg | grep "leaked bytes")
    
    # Print the arguments and the result
    echo "Test #$total_tests: $arg -> $result"
    
    # Check the result and print "OK" if it returns "OK"
    if [ "$result" == "OK" ]; then
      echo "OK"
    fi

    # Sleep for a bit
    sleep 0.1
  done
done

# Print the total number of tests
echo "Total number of combinations tested: $total_tests"