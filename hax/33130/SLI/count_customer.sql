delimiter &
create procedure count_customer(out var int)
begin
	select count(*) into var from customer;	
end;

