delimiter $
CREATE TRIGGER trans_log
AFTER UPDATE
ON product
for each row
BEGIN
     insert into txnlog values(new.p_id,old.product_price,new.product_price,user(),curdate());
END;


