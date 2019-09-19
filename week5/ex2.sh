#!/bin/bash
if test ! -f "nums.txt"; then
	echo "1" >> "nums.txt"
fi
while true; do
    if ln "nums.txt" "lockfile" ; then
        n=$(cat "nums.txt" | tail -n 1)
        echo "$((n + 1))" >> nums.txt
        rm "lockfile"
    fi
done

