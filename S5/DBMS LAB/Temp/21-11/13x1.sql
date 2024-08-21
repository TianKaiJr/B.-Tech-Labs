drop table employee;

create table employee (eno int,ename varchar(20),sal int );

insert into employee values(4,'ABC',50000);
insert into employee values(5,'BCD',35000);
insert into employee values(6,'CDE',45000);
insert into employee values(7,'EFG',55000);
insert into employee values(8,'GHI',65000);

select * from employee;

create trigger sal_diff after update on employee for each row
when (NEW.eno > 0)
declare 
	diff number;
begin
	diff := :NEW.sal - :OLD.sal;
	dbms_output.put_line('NEW Salary = '|| :NEW.sal ||chr(13)||chr(10)||'OLD Salary = '|| :OLD.sal );
	dbms_output.put_line('Difference in Salary = '||diff);
end;
/

update employee set sal=98745 where eno=6;

