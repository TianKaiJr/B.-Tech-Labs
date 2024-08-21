echo "SUM OF 'n' EVEN"

echo -n "Enter 'n' = "
read n

j=2*$n
sum=0

for((i=1;i<=j;i++))
do
	if [ $((i%2)) -eq 0 ]; then
		sum=$((sum+i))
	fi
done

echo "SUM = $sum"
