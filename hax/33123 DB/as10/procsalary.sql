delimiter $
create TRIGGER procsalary
before insert
 on salary
FOR EACH ROW
begin
    set new.da=0.50*new.basic;
    set new.hra=500;
    set new.it=0.02*new.basic;
end;


