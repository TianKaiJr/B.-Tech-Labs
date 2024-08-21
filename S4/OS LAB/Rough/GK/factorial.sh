echo "enter the number"
read n
f=1
while [ $n -gt 1 ]
do 
f=$((f=f*n))
n=$((n-1))
done 
echo $f
