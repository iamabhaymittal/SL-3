delimiter $
create trigger update_selects_amt
before insert on selects
for each row
begin
	set new.total_amount=(select unit_price from product where p_id=new.p_id)*new.quantity;
end;
