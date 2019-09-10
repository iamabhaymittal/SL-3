delimiter &
create procedure net_salary(in empno int)
begin
	declare total_allowance,total_deduction,netpay int;
	set total_allowance=(select basic from salary where salary.eno=empno)+(select da from salary where salary.eno=empno)+(select hra from salary where salary.eno=empno);
	set total_deduction=(select it from salary where salary.eno=empno);
	set netpay=total_allowance-total_deduction;
	select total_allowance;
	select total_dedeuction;
	select netpay;
	insert into net_salary values(eno,total_allowance,total_deduction,netpay);	
end;
