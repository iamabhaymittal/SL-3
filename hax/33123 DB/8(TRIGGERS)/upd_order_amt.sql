delimiter $
CREATE TRIGGER amt_update
BEFORE INSERT 
on selects
for each row
BEGIN
  update orders set total_amt=total_amt+new.tot_amt where or_id=new.or_id;
END;


