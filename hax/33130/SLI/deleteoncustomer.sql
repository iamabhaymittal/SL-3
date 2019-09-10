/*delete corresponding records from selects and orders after delete on customer table*/
delimiter &
create trigger deleteoncustomer
before delete on customer
for each row
begin
	delete from selects where or_id=(select or_id from orders where cust_no=old.cust_id);
	delete from orders where cust_no=old.cust_id;   
end;
 
