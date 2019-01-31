choice=0
ans=0
while true; do
	echo "Enter Number 1"
	read num1;
	echo "Enter Number 2"
	read num2;

	printf "What Operation do you want to perform\n1)Addition\n2)Subtraction\n3)Multiplication\n4)Division\n"
	read choice;

	case $choice in
		1) ans=`expr $num1 + $num2`
		printf "$num1 + $num2 = $ans";;
		2) ans=`expr $num1 - $num2`
		printf "$num1 - $num2 = $ans";;
		3) ans=`expr $num1 \* $num2`
		printf "$num1 * $num2 = $ans";;
		4) ans=`expr $num1 / $num2`
		printf "$num1 / $num2 = $ans";;
	esac

	printf "\nDo you want to continue?\nEnter Any Number to Continue\n1 to Continue\n"
	read choice

	if [[ $choice -ne 1 ]]; then
		break
	fi
done
