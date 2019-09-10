create procedure net_sal_proc(IN empno int)
begin
    declare netpay int;
    declare tot_allowance int;
    declare tot_deduction int;
    set tot_allowance=(select basic from salary where eno=empno)+(select da from salary where eno=empno)+(select hra  from salary where eno=empno);
    set tot_deduction=(select it from salary where eno=empno);
    set netpay=tot_allowance-tot_deduction;
    select tot_allowance;
    select tot_deduction;
    select netpay;
    insert into net_salary values(eno,tot_allowance,tot_deduction,netpay);
end;

