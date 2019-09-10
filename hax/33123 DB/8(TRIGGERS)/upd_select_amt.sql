delimiter $
CREATE TRIGGER stock_pupdate
BEFORE INSERT
ON selects
FOR EACH ROW
BEGIN
   set new.tot_amt=(select product_price from product where p_id=new.p_id)*new.qty;
END;
