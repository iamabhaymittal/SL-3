delimiter &
create procedure customer_details(in var int)
begin
	select * from customer where cust_id=var;	
end;
