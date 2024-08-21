drop table customers;
drop table premium;
drop table nonpremium;

create table customers (
	accno int,
	cname varchar(20),
	balamount int,
	doj date );
	
insert into customers values (101,'ABC',45000,'22-11-2012');
insert into customers values (50,'BCD',147000,'23-07-2005');
insert into customers values (3,'CDE',30000,'21-12-2011');
insert into customers values (90,'EFG',25000,'09-08-2015');
insert into customers values (12,'GHI',150000,'01-05-2000');

create table premium (
	accno int,
	cname varchar(20),
	balamount int,
	doj date );
	
create table nonpremium (
	accno int,
	cname varchar(20),
	balamount int,
	doj date );
	
declare
	ano customers.accno%type;
	aname customers.cname%type;
	abal customers.balamount%type;
	adoj customers.doj%type;
	
	cursor femp is select accno,cname,balamount,doj from customers;
	begin
		open femp;
		loop
			FETCH femp into ano,aname,abal,adoj;
			exit when femp%notfound;
			if (abal>100000 and adoj < '01-01-2010') then
				insert into premium values (ano,aname,abal,adoj);
			else
				insert into nonpremium values (ano,aname,abal,adoj);
			end if;
		end loop;
		close femp;
	end;	
/

select * from customers;
select * from premium;
select * from nonpremium;
