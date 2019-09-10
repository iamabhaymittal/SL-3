delimiter &
create procedure odd_even_sum(out var1 int,out var2 int)
begin
	declare i int ;	
	set var1=0;
	set var2=0;
	set i=1;
	while i<=100 do
		if i%2=0 then
			set var1=var1+i;
		else
			set var2=var2+i;
		end if;
		set i=i+1;
	end while;
end;
