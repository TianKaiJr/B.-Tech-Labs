echo "FACTORIAL OF 'n'"

echo -n "Enter 'n' >> "
read n

fact=1
z=0

if [ $n == $z ] ; then
	echo "FACTORIAL OF 0 >> 1"
else 
	for((i=2;i<=n;i++))
	do
		fact=$((fact*i))
	done
fi

echo -n "FACTORIAL OF '$n' >> $fact"

 
