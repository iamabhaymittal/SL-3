delimiter $
CREATE TRIGGER error_product
BEFORE INSERT
ON selects
FOR EACH ROW
BEGIN
IF (NEW.qty< 0) THEN
SIGNAL SQLSTATE '80000'
SET MESSAGE_TEXT='Quantity cannot be less than 0';
END IF;
END;
