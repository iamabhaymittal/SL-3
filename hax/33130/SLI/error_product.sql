delimiter &
create trigger error_product 
before insert
on product
for each row
begin
	if (new.stock<0) then
	signal sqlstate '80000'
	set message_text='stock cannot be negative';
end if;
end;
 
