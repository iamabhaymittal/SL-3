delimiter &
create trigger upper_customer
after insert on customer
for each row
begin 
	set new.fname=upper(new.fname);
	set new.lname=upper(new.lname);
end;
&
