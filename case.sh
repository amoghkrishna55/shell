echo "Enter 1 2 3: "
read num1
echo "Number received:"
case "$num1" in
	"1") echo "The number is 1"
		;;
	"2") echo "The number is 2"
		;;
	"3") echo "The number is 3"
		;;
	*) echo "Invalid number"
		;;
esac
