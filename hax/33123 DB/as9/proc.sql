delimiter $
create procedure cust_count(out var int)
begin
     select count(*) into var from customer;
end;
