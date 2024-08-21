echo "enter two numbers"
read a b
if [ `expr $a` -gt `expr $b` ]
then 
echo $a "is greater than" $b
else
echo $b "is greater than" $a
fi
