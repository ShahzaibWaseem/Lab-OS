echo "Enter a Number"
read num;
i=0
ans=0
while [[ i -le 10 ]]; do
	ans=`expr $num \* $i`
	echo "$num * $i = $ans"
	i=`expr $i + 1`
done