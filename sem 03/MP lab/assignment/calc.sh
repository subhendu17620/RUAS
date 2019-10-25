#!/bin/bash
start=`date +%s%N`
for i in {1..1000}; do ./assign; done;
end=`date +%s%N`
echo "Execution Time : $(((end-start)/1000)) nanoseconds"




