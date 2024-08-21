drop table theatre;

create table theatre (mvid varchar(3),mvname varchar(20),mvlang varchar(10),revrat float);

create table outdated12 (omvid varchar(3),omvname varchar(20));

insert into theatre values ('S01','Vikram','Tamil',9.8);
insert into theatre values ('S02','LEO','Tamil',7.8);
insert into theatre values ('S03','Kaithi','Tamil',9.2);
insert into theatre values ('S04','Mrs Marvels','Eng',6.2);

create trigger updater12 after update on theatre for each row
declare
	id varchar2 := :NEW.mvid;
	name varchar2 := :NEW.mvname;
	rating float := :NEW.revrat;
begin
	if (rating < 5) then 
		delete row from theatre where mvid=id;
	END if;
	insert into outdated values (id,name);
end;
/

update theatre set revrat=4.9 where mvid='S04';

select * from theatre;
select * from outdated;

		
			 
