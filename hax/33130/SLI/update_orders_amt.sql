delimiter $
create trigger update_selects_amt
after insert on selects
for each row
begin
	update orders set total_amt=total_amt+new.total_amount where or_id=new.or_id;
end;
