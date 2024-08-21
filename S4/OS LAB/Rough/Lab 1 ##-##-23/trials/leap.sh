echo "LEAP YEAR CHECK"

echo -n "Enter Year = "
read year

if [ $((year%4)) -eq 0 ]; then
	echo "$year is a Leap Year"
else
	echo "$year is a not Leap Year"
fi
