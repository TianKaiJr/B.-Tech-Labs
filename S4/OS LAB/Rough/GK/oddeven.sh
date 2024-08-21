echo "Enter number"
read a
if [ `expr $a % 2` -eq 0 ]
then 
echo "number is even"
else
echo "number is odd"
fi
