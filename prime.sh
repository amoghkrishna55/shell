echo "Enter a number: "
read num

echo "Prime numbers up to $num:"
for ((i = 2; i <= num; i++)); do
    is_prime=1
    for ((j = 2; j * j <= i; j++)); do
        if [ $((i % j)) -eq 0 ]; then
            is_prime=0
            break
        fi
    done
    if [ $is_prime -eq 1 ]; then
        echo $i
    fi
done
