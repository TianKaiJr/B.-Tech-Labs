#Jiffina Rodrigues
#02
echo "enter three numbers:"
read a b c
if [ $a -gt $b ] && [ $a -gt $c ]
then 
echo "largest is" $a
else
if [ $b -gt $c ] && [ $b -gt $a ]
then
echo "largest is" $b
else
echo "largest is" $c
fi
fi



