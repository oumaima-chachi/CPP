#!/bin/bash

BINARY="./PmergeMe"

PASS=0
FAIL=0

run_test() {
    local desc=$1
    shift
    local numbers=("$@")
    local input="${numbers[*]}"
    local sorted=$(echo "$input" | tr ' ' '\n' | sort -n | tr '\n' ' ')
    local output=$($BINARY $input | tr '\n' ' ')

    if [ "$output" = "$sorted" ]; then
        echo "✓ PASS [$desc]: $input"
        PASS=$((PASS + 1))
    else
        echo "✗ FAIL [$desc]"
        echo "  input:    $input"
        echo "  expected: $sorted"
        echo "  got:      $output"
        FAIL=$((FAIL + 1))
    fi
}

generate_random() {
    local count=$1
    shuf -i 1-1000 -n $count | tr '\n' ' '
}

echo "==============================="
echo "  Ford-Johnson Sort Full Tests"
echo "==============================="

# edge cases
echo ""
echo "--- Edge cases ---"
run_test "1 element"    42
run_test "2 sorted"     1 2
run_test "2 reversed"   2 1
run_test "3 elements"   3 1 2
run_test "already sorted 8"   1 2 3 4 5 6 7 8
run_test "reverse sorted 8"   8 7 6 5 4 3 2 1
run_test "all same"     5 5 5 5 5 5 5 5

# odd sizes
echo ""
echo "--- Odd sizes ---"
for size in 3 5 7 9 11 13 15 17 19 21; do
    nums=($(generate_random $size))
    run_test "$size elements" "${nums[@]}"
done

# even sizes
echo ""
echo "--- Even sizes ---"
for size in 2 4 6 8 10 12 14 16 18 20; do
    nums=($(generate_random $size))
    run_test "$size elements" "${nums[@]}"
done

# powers of 2
echo ""
echo "--- Powers of 2 ---"
for size in 2 4 8 16 32 64 128; do
    nums=($(generate_random $size))
    run_test "power of 2: $size" "${nums[@]}"
done

# powers of 2 minus 1
echo ""
echo "--- Powers of 2 minus 1 ---"
for size in 1 3 7 15 31 63 127; do
    nums=($(generate_random $size))
    run_test "pow2-1: $size" "${nums[@]}"
done

# powers of 2 plus 1
echo ""
echo "--- Powers of 2 plus 1 ---"
for size in 3 5 9 17 33 65 129; do
    nums=($(generate_random $size))
    run_test "pow2+1: $size" "${nums[@]}"
done

# random sizes
echo ""
echo "--- Random sizes (3 runs each) ---"
for size in 4 8 16 32 64; do
    for run in 1 2 3; do
        nums=($(generate_random $size))
        run_test "$size elements run $run" "${nums[@]}"
    done
done

# large sizes
echo ""
echo "--- Large sizes ---"
for size in 100 200 500 1000; do
    nums=($(generate_random $size))
    run_test "$size elements" "${nums[@]}"
done

# already sorted
echo ""
echo "--- Already sorted ---"
for size in 4 8 16 32 64; do
    nums=($(seq 1 $size | tr '\n' ' '))
    run_test "sorted $size" $nums
done

# reverse sorted
echo ""
echo "--- Reverse sorted ---"
for size in 4 8 16 32 64; do
    nums=($(seq $size -1 1 | tr '\n' ' '))
    run_test "reversed $size" $nums
done

echo ""
echo "==============================="
echo "  Results: $PASS passed, $FAIL failed"