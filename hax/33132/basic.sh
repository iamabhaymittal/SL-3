#!/ bin / bash 

a=3
b=6

read -p "Enter number a : " a
read -p "Enter number b : " b
#c=$((a*b)) 

c=`expr $a "*" $b`
c=`expr $a \* $b`
c=`expr $a \+ $b`
c=`expr $a + $b`
c=`expr $a "+" $b`

echo "$c"

