
a=0 

  
 
while (( $a < 10 ))
#while [ $a -lt 10 ]
do  
    echo $a
      
    a=`expr $a + 1`
    #a=$((a+1)) 
done 

