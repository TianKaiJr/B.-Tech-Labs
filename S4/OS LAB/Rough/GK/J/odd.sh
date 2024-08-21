#Jiffina Rodrigues
#02
echo "enter a number"
read a
if [ `expr $a % 2` -eq 0 ]
then
echo "even number"
else
echo "odd number"
fi
