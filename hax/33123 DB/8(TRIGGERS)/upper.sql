delimiter $
CREATE TRIGGER upper_name
BEFORE INSERT
ON customer
FOR EACH ROW
BEGIN
   set new.cust_name=upper(new.cust_name);
END;
