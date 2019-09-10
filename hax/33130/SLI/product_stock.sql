/* update stock*/
delimiter &
create trigger product_stock 
after insert on selects
for each row
begin
	update product set stock = stock - new.quantity where p_id=new.p_id;	
end;
