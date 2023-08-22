echo "Enter a number: "
read num1
echo "Enter number 2: "
read num2
if [ $num1 -gt $num2 ]
then
	echo "$num1 greater"
else
	echo "$num2 greater"
fi
