#!/bin/bash
var=quectel

echo $var

printf "Input a character: "
read -n 1 char
case $char in
   [a-zA-Z])
       printf "\nletter\n"
       ;;
   [0-9])
        printf "\nDigit\n"
       ;;
   [0-9])
       printf "\nDigit\n"
       ;;
   [,.?!])
       printf "\nPunctuation\n"
       ;;
 *)
    printf "\nerror\n"
esac


