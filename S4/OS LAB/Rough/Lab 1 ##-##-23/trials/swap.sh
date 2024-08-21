echo "NUM 1"
read n1
echo "NUM 2"
read n2

echo "NUM 1 >> $n1"
echo "NUM 2 >> $n2"

temp=$n1
n1=$n2
n2=$temp

echo "AFTER SWAP"
echo "NUM 1 >> $n1"
echo "NUM 2 >> $n2"

