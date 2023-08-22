echo "Enter a number :0 : "
read num1
num=1
while [ $num -lt 11 ]
do
	echo "$num1 X $num = `expr $num \* $num1`"
	num=`expr $num + 1`
done
