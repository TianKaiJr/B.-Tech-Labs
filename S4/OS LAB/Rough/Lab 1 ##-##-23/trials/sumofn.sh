
echo "SUM OF N NUMBERS"
echo -n "Enter 'n' >> "
read n

sum=0

for((i=0;i<n;i++))
do 
	echo -n "Enter Num $((i+1)) >> " 
	read m
	sum=$((sum+m))
done

echo "SUM >> $sum"
