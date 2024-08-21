echo "ODD OR EVEN"
echo -n "Enter 'n' >> "
read n

if [ $((n%2)) -eq 0 ]; then
	echo "$n is EVEN"
else
	echo "$n is ODD"
fi

