/*check quantity with stock present*/
delimiter &
create trigger stock_val
before insert on selects
for each row
begin
	if (new.quantity > (select stock from product where p_id=new.p_id)) then
	signal sqlstate '80000'
	set message_text='Qunatity not available';
end if;	
end;
