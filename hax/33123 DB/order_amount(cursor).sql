delimiter &
create procedure order_amount(out tot_amt int,in id int)
begin
	declare a int;
	declare j int default 0;
	declare s cursor for select total_amount from selects where or_id=id;
	declare continue handler for not found set j=1;
	set tot_amt=0;
	open s;
	fetch s into a;
	while j=0 do
		set tot_amt=tot_amt+a;
		fetch s into a;
	end while;
	select tot_amt;
	close s;
end;
