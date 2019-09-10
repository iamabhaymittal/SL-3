#! /bin/bash

#function for creating records
createRecord()
{
	i=1
	read -p "Enter the total number of students : " n
	
	while [ $i -lt $((n+1)) ]
	do 
		echo -e "\nEnter information for student $i :- \n"
		read -p "Enter roll no :- " rollno
		read -p "Enter name :- " name
		read -p "Enter marks :- " marks
		
		echo -e "$rollno\t\t$name\t\t$marks\t" >> "$fname"  	#record written in file
		
		i=$((i+1))
		
	done	
}

#function to display records
displayRecord()
{
	echo -e "Contents of Student Database :- (sorted acc. to roll no)\n"
	echo -e "********************************************"
	echo -e "Roll No.\tName\t\tMarks"
	echo -e "********************************************"
	sort -n $fname		#sort records acc to roll no and display
	echo -e "********************************************"	
}

#function to insert a record
insertRecord()
{
	echo -e "\nEnter information for student :- \n"
	read -p "Enter roll no :- " rollno
	read -p "Enter name :- " name
	read -p "Enter marks :- " marks
		
	echo -e "$rollno\t\t$name\t\t$marks\t" >> "$fname"
}

#function to search record
searchRecord()
{
	echo -e "\nHow do you want to search :- \n\t1)By ROLL_NO\n\t2)By NAME"
	read ch1
	
	case "$ch1" in
	
	"1")read -p "Enter the roll no you want to search :- " searchno
	
	echo -e "********************************************"
	echo -e "Roll No.\tName\t\tMarks" 
	echo -e "********************************************"
	
	grep -w "$searchno" "$fname"
	 
	echo -e "********************************************"
	 
	 if test $? -eq 1     #grep gives 1 if record not found
	 then
	 	echo "Record not found!!!"
	 else
	 	echo "Record found!!!"
	 
	 fi;;
	 
	 "2")read -p "Enter the name you want to search :- " searchname
	
	echo -e "********************************************"
	echo -e "Roll No.\tName\t\tMarks" 
	echo -e "********************************************"
	
	grep -w "$searchname" "$fname"
	 
	echo -e "********************************************"
	 
	 if test $? -eq 1
	 then
	 	echo "Record not found!!!"
	 else
	 	echo "Record found!!!"
	 
	 fi;;
	 
	 *) echo -e "\nPlease enter valid choice!";;
	 
	 esac
	 	
}

#function to delete a record
deleteRecord()
{
	echo -e "\nHow do you want to delete :- \n\t1)By ROLL_NO\n\t2)By NAME"
	read ch2
	
	case "$ch2" in
	
	"1")read -p "Enter the roll no you want to delete :- " delno
	echo -e "\n"
	
	 grep -w "$delno" "$fname"   	#-w to check for whole word matching,and not substring
	 
	 if test $? -eq 1
	 then
	 	echo "Record not found!!!"
	 else
	 	grep -vw "$delno" $fname >temp.txt 	#copies all records except the one to be deleted
	 	echo -e "Record deleted successfully!!!\n"
	 	echo -e "Updated records in the file :- \n"
	 	echo -e "********************************************"
		echo -e "Roll No.\tName\t\tMarks" 
		echo -e "********************************************"
		sort -n temp.txt
		echo -e "********************************************"
		rm $fname
		mv temp.txt $fname
	 
	 fi;;
	 
	 "2")read -p "Enter the name you want to delete :- " delname
	echo -e "\n"
	
	 grep -w "$delname" "$fname"   	#-w to check for whole word matching,and not substring
	 
	 if test $? -eq 1
	 then
	 	echo "Record not found!!!"
	 else
	 	grep -vw "$delname" $fname >temp.txt 	#copies all records except the one to be deleted
	 	echo -e "Record deleted successfully!!!\n"
	 	echo -e "Updated records in the file :- \n"
	 	echo -e "********************************************"
		echo -e "Roll No.\tName\t\tMarks" 
		echo -e "********************************************"
		sort -n temp.txt
		echo -e "********************************************"
		rm $fname
		mv temp.txt $fname
	 
	 fi;;
	 
	 *) echo -e "\nPlease enter valid choice!";;
	 
	 esac
	 	
}

#function to modify record
modifyRecord()
{
	echo -e "\nHow do you want to search :- \n\t1)By ROLL_NO\n\t2)By NAME"
	read ch3
	
	case "$ch3" in
	
	"1")read -p "Enter the roll no of record you want to modify :- " modno
	echo -e "\n"
	
	 grep -w "$modno" "$fname"
	 
	 if test $? -eq 1
	 then
	 	echo "Record not found!!!"
	 else
	 	grep -vw "$modno" $fname >temp.txt
	 	
	 	echo -e "\nEnter updated information for student :- \n"
		read -p "Enter roll no :- " rollno
		read -p "Enter name :- " name
		read -p "Enter marks :- " marks	
		echo -e "$rollno\t\t$name\t\t$marks\t" >> "temp.txt"
		
	 	echo -e "Record modified successfully!!!\n"
	 	echo -e "Updated records in the file :- \n"
	 	echo -e "********************************************"
		echo -e "Roll No.\tName\t\tMarks" 
		echo -e "********************************************"
		sort -n temp.txt
		echo -e "********************************************"
		rm $fname
		mv temp.txt $fname
	 
	 fi;;
	 
	 "2")read -p "Enter the name of record you want to modify :- " modname
	echo -e "\n"
	
	 grep -w "$modname" "$fname"
	 
	 if test $? -eq 1
	 then
	 	echo "Record not found!!!"
	 else
	 	grep -vw "$modname" $fname >temp.txt
	 	
	 	echo -e "\nEnter updated information for student :- \n"
		read -p "Enter roll no :- " rollno
		read -p "Enter name :- " name
		read -p "Enter marks :- " marks	
		echo -e "$rollno\t\t$name\t\t$marks\t" >> "temp.txt"
		
	 	echo -e "Record modified successfully!!!\n"
	 	echo -e "Updated records in the file :- \n"
	 	echo -e "********************************************"
		echo -e "Roll No.\tName\t\tMarks" 
		echo -e "********************************************"
		sort -n temp.txt
		echo -e "********************************************"
		rm $fname
		mv temp.txt $fname
	 
	 fi;;
	 
	 *) echo -e "\nPlease enter valid choice!";;
	 
	 esac
}

#main started
n=0
x=0
choice=0

echo -e "\n     *** STUDENT DATABASE *** \n"

read -p "Please enter the name of file :- " fname

while [ $choice != 7 ]
do

	echo -e "\n     ***WELCOME TO THE MENU*** \n"
	echo -e "1)Create Record\n2)Display Record\n3)Insert Record\n4)Search Record\n5)Delete Record\n6)Modify Record\n7)Exit \n "
	
	read -p "Please enter your choice : " choice
	
	case "$choice" in

	"1") createRecord
		echo -e "\nRecords created successfully!!!";;
		
	"2") displayRecord;;
	
	"3") insertRecord
		echo -e "\nRecord inserted successfully!!!";;
		
	"4") searchRecord;;
	"5") deleteRecord;;
	"6") modifyRecord;;
	"7") echo "\nExited successfully...Thank you!!!\n";;
	 *)  echo "Please enter valid choice!";;
	
	esac


done

