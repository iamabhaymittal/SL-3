delimiter $
create procedure proc_grade()
begin
     declare grade char(5);
     declare j int default 0;
      declare mark int;
     declare s cursor for select marks from student;
     declare continue handler for not found set j=1;
     open s;
     fetch s into mark;
     while j=0 DO
      	   if mark>=80 THEN
      	        set grade="O";
      	   ELSEIF mark>=70 and mark<80 then
      	        set grade="A+";
      	  ELSEIF mark>=60 and mark<70 then
      	        set grade="A";
      	   ELSEIF mark>=50 and mark<60 then
      	        set grade="B+";
      	  ELSEIF mark>=40 and mark<50 then
      	        set grade="B";
      	   else
      	        set grade="F";
      	   end if;
      	select grade;
      	 fetch s into mark;
     end while;
     close s; 

end;

