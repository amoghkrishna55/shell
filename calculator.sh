echo "Enter first number:  "
read num1
echo "Enter second number: "
read num2
echo "Enter + - * /: "
read opt
case "$opt" in
	"+") echo "The addition is `expr $num1 + $num2`"
		;;
	"-") echo "The substraction is `expr $num1 - $num2`"
		;;
	"*") echo "The multiplication is `expr $num1 \* $num2`"
		;;
	"/") echo "The division is `expr $num1 / $num2`"
		;;
esac
