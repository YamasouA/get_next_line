echo "===================="
echo 'BUFFER_SIZE' "$1"
echo "====================="

gcc -Wall -Werror -Wextra -D BUFFER_SIZE="${1:-256}" *.c

for file in ./test/*; do
    echo "-------------------------------"
    echo "$file"
    cat -e "$file"
    ./a.out "$file" > result
    cat -e result
done