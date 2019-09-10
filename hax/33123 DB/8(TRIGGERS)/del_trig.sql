delimiter $
CREATE TRIGGER del_trig
BEFORE DELETE
ON customer
for each row
BEGIN
    DECLARE a integer;
    set a=(select or_id from orders where  cust_no=old.cust_id);
    delete from selects where or_id=a;
    delete from orders where orders.cust_no=old.cust_id;
   
END;


