drop table employee;

create table employee (
     eid varchar(5),
     ename varchar(15),
     salary int,
     designation varchar(15) );


insert into employee values('e1','ABC',55000,'SW Designer');
insert into employee values('e2','BCD',75000,'Manager');
insert into employee values('e3','CDE',70000,'Vice Manager');
insert into employee values('e4','EFG',85000,'Zonal Manager');
insert into employee values('e5','GHI',100000,'CEO');


declare
	empname employee.ename%type;
	empsalary employee.salary%type;
	cursor high is select ename,salary from employee order by salary desc;
	begin
		OPEN high;
		loop
			FETCH high into empname,empsalary;
			exit when high%notfound;
			dbms_output.put_line(empname||'	'||empsalary);
		end loop;
		CLOSE high;
	end;
/

