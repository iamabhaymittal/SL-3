delimiter $
CREATE TRIGGER stock_p
AFTER INSERT
ON selects
FOR EACH ROW
BEGIN
   update product set stock=stock-new.qty where p_id=new.p_id;
END;
