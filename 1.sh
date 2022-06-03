#!/bin/bash  
read  var
echo $var | tr -s -c a-zA-Z "\n" | sort | uniq -c | sort -n -r | head -3 
