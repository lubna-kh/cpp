#!/bin/bash

# Path to your RPN executable
RPN="./RPN"

# Define test cases: "input | expected_output"
tests=(
  "3 4 + | 7"
  "5 1 2 + 4 * + 3 - | 14"
  "8 9 * 9 - 9 - 9 - 4 - 1 + | 42"
  "7 2 / | 3"
  "9 3 / 2 * | 6"
  "1 | Error"
  "1 + | Error"
  "+ 1 2 | Error"
  "1 2 3 + | Error"
  "5 a + | Error"
  "4 0 / | Error: Division by Zero!"
)

echo "🔹 Running RPN tests..."
echo "========================"

for t in "${tests[@]}"; do
  input="${t%%|*}"
  expected="${t##*| }"
  output=$($RPN "$input" 2>&1)
  if [[ "$output" == "$expected" ]]; then
    echo "✅ '$input' → $output"
  else
    echo "❌ '$input'"
    echo "   Expected: $expected"
    echo "   Got:      $output"
  fi
done
