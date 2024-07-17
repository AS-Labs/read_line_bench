#!/bin/bash
echo "starting C" > ./out
(time ./test-linebyline_C) >> ./out 2>&1 
echo "starting Rust" >> ./out
(time ./test-linebyline_RS) >> ./out 2>&1 
echo "starting Go" >> ./out
(time ./test-linebyline_GO) >> ./out 2>&1 
echo "starting Zig" >> ./out
(time ./test-linebyline_ZIG) >> ./out 2>&1 
echo "starting Cpthreads" >> ./out
(time ./test-linebyline_C_concurrent) >> ./out 2>&1  
echo "starting wc" >> ./out
(time wc -l ./data.txt) >> ./out 2>&1 
echo "starting python3" >> ./out
(time python3 ./test-linebyline_py.py) >> ./out 2>&1 

echo "Lang,Time" > ./tmpF
grep -E "start|real" out|awk '{ print $2 }'|paste - -|sed 's/\t/,/g' >> ./tmpF
column -s, -t < ./tmpF > results.txt
rm -f ./tmpF
rm -f ./out
#echo "bash starting"
#starting bash ./test-linebyline_BASH.sh
