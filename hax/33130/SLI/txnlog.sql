/*create txn log for every stock change*/
delimiter &
create trigger txnlog
after update on product
for each row
begin
	insert into txnlog values(new.p_id,old.unit_price,new.unit_price,user(),curdate());	
end;
