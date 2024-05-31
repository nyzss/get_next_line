#!bin/bash

if [[ $1 ]]
	then
		file_name="$1"
else
		file_name="text.txt"
fi
echo "------------------------------------------------"
echo "TEST WITH SET BUFFER_SIZE IN HEADER"
echo " "
cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out
./a.out "$file_name"

if [[ $2 == "d" ]]
	then
		valgrind --leak-check=full --show-leak-kinds=all -s ./a.out "$file_name"
fi

if [[ $2 == "b" ]]
	then
		echo "------------------------------------------------"
		echo "TEST WITH BUFFER_SIZE OF 1"
		echo " "

		cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out -D BUFFER_SIZE=1
		./a.out "$file_name"

		echo "------------------------------------------------"
		echo "TEST WITH BUFFER_SIZE OF 7"
		echo " "

		cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out -D BUFFER_SIZE=7
		./a.out "$file_name"

		echo "------------------------------------------------"
		echo "TEST WITH BUFFER_SIZE OF 42"
		echo " "

		cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out -D BUFFER_SIZE=42
		./a.out "$file_name"

		echo "------------------------------------------------"
		echo "TEST WITH BUFFER_SIZE OF 100000"
		echo " "

		cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out -D BUFFER_SIZE=100000
		./a.out "$file_name"
fi

if [[ $2 == "D" ]]
	then
		cc main.c get_next_line.c get_next_line_utils.c -Wall -Werror -Wextra -g -I. -o a.out -D BUFFER_SIZE="$3"
		./a.out "$file_name"
fi