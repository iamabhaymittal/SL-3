delimiter $
CREATE TRIGGER stock_pvalid
AFTER INSERT
ON selects
FOR EACH ROW
BEGIN
   DECLARE a integer;
   set a=(select stock from product where  p_id=new.p_id);
IF (NEW.qty> a) THEN
SIGNAL SQLSTATE '80000'
SET MESSAGE_TEXT='Quantity Greater Than stock cant Be Entered';
END IF;
END;
