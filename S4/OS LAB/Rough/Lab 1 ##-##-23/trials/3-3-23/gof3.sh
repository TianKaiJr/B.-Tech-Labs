echo "Greatest Of 3 Numbers"

echo -n "Enter the num1 = "
read num1
echo -n "Enter the num2 = "
read num2
echo -n "Enter the num3 = "
read num3

if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "Greatest Of 3 NUMs = $num1"
elif [ $num2 -gt $num3 ] ;
then
    echo "Greatest Of 3 NUMs = $num2"
else
    echo "Greatest Of 3 NUMs = $num3"
fi
