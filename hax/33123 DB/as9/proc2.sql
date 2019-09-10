delimiter $
create procedure odd_even(out var1 int,out var2 int)
begin
    DECLARE i int;
    set var1=0;
    set var2=0;
    set i=1;
    WHILE i<=100 DO
	    if i%2=0 THEN
	    	set var1=var1+i;
	    else
	    	set var2=var2+i;
	    end if;
	    set i=i+1;
    END WHILE;
end;
