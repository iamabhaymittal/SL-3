#! /bin/bash
i="y"
while [ $i = "y" ]
do
clear
echo "1.View the Data Base "
echo "2.View Specific Records "
echo "3.Add Records "
echo "4.Delete Records "
echo "5.Update"
echo "6.Exit "
echo "Enter your choice "
read ch
    case $ch in
        1)cat student;;
        2)echo "Enter id "
          read id
            grep -i "$id" student;;
        3)echo "Enter new std id "
          read tid
          echo "Enter new name:"
          read tnm
          echo "Enter designation "
          read des
          echo "Enter college name"
          read college
          echo "$tid    $tnm    $des    $college">>student;;
        4)echo "Enter Id"
          read id
          grep -w "$id" student
	  if [ $? -ne 0 ]
	  then 
		echo "record not found"
	  fi
          grep -vw "$id" student >dbs1    
          echo "Record is deleted"
          cat dbs1
	  rm student
	  mv dbs1 student;;
	5)echo "Enter id"
	  read id
	  count=0;;          
        6)exit;;
        *)echo "Invalid choice ";;
    esac
echo "Do u want to continue ?"
read i
if [ $i != "y" ]
then
    exit
fi
done       
