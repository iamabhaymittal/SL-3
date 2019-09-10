delimiter $
create procedure cust_display(in var1 int)
begin
     select * from customer where cust_id=var1;
end;
