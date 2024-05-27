#!bin/bash

if [[ $1 ]]
	then
		file_name="$1"
else
		file_name="text.txt"
fi
cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -I. -o a.out
./a.out "$file_name"

if [[ $2 == d ]]
	then
		valgrind ./a.out
fi
