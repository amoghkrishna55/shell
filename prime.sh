echo "Enter a number: "
read num
num1=1
if [ $num -le 2 ]
then 
	echo "Not a prime"
else 
	while [ $num1 -le $num ]
	do
		num2=1
		a=1
		while [ $num2 -le $num1 ]
		do
			if [ `expr $num2 % 2` -eq 0 ]
			then
				a=0
				break
			fi
			if [ $a -eq 1 ]
			then
				echo $num2
			fi
			num2=`expr $num2 + 1`
		done
		num1=`expr $num1 + 1`
	done
fi

