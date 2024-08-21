#Jiffina Rodrigues
#02
echo "1.add"
echo "2.substract"
echo "3.multipy"
echo "4.divide"
while :
do
echo "Enter two numbers:"
read a b
echo "Enter your choice:"
read choice
case $choice in
"1")
sum=$(($a+$b))
echo "sum is" $sum
;;
"2")
sub=$(($a - $b ))
echo "difference is" $sub
;;
"3")
mul=$(( $a * $b ))
echo "product is" $mul
;;
"4")
div=$(( $a / $b ))
echo "quotient is" $div
;;
*)
echo "invalid choice"
exit
esac
done


