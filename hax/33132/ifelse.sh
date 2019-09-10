a=7
b=7

if (( $a > $b ))
then
	echo "a is greater than b"

elif (( $a == $b ))
then
	echo "a is equal to b"

else
	echo "a is less than b"
fi

#double round brackets : > or <
#single square brackets : -lt or -gt
#double square brackets : > or <
