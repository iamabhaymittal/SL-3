for a in 1 2 3 4 5 6 7

do
	if [ $a == 4 ]
	then
		#break
		continue
	fi
	echo $a
done
