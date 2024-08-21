echo "FIBONACCI SERIES"

n1=0
n2=1
n3=$((n1+n2))

echo -n "Enter Limit >> "
read lim

echo -n "FIBONACCI SERIES upto $lim >> "
echo -n "$n1 $n2"
for (( i=3 ; i <= lim ; ++i ))
do
	echo -n " $n3"
	n1=$n2
	n2=$n3
	n3=$((n1+n2))
done

echo
