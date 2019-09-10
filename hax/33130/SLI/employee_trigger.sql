delimiter & 
create trigger employee_trigger 
before insert on salary
for each row
begin
	set new.da=0.59*new.basic ;
	set new.hra=500 ;
	set new.it=0.02*new.basic ;	 
end;

