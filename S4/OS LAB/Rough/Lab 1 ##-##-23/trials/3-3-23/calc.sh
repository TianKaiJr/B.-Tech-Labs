
echo "SIMPLE CALCULATOR"
echo -n "Enter NUM 1 = "
read num1
echo -n "Enter NUM 2 [ != 0 ] = "
read num2

ch=0

while [ $ch != 5 ] ;
do
    echo "              MENU"
    echo $"1.ADD 2.SUB 3.MUL 4.DIV 5.EXIT"
    echo -n "Enter Choice [1,2,3,4,5] >> "
    read ch

    if [ $ch == 1 ] ;
    then
        result=$((num1+num2))
        echo "RESULT >> $result"
    fi

    if [ $ch == 2 ] ;
    then
        result=$((num1-num2))
        echo "RESULT >> $result"
    fi

    if [ $ch == 3 ] ;
    then
        result=$((num1*num2))
        echo "RESULT >> $result"
    fi

    if [ $ch == 4 ] ;
    then
        result=$((num1/num2))
        echo "RESULT >> $result"
    fi

done
