delimiter //

DROP PROCEDURE IF EXISTS pr1;

create procedure pr1(OUT sum int)
begin

declare a int;
select a;
set a=200;
set sum=0;

while a<=200 do
if a%2==0 then
set sum += a;
end if;
set a=a+1;
end while;

end


