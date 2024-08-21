echo "enter two numbers"
read a b
if [ `expr $a` -eq `expr $b` ]
then 
echo "numbers are equal"
else
echo "numbers are not equal"
fi
