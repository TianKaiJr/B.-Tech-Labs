echo "REVERSE OF NUMBER"

echo -n "Enter The Number >> "
read n

while [ $n -ne 0 ] ;
do
	rem=$((n%10))
	rev=$(( (rev*10)+rem ))
	n=$((n/10))
done

echo "REVERSE >> $rev"
