#include<stdio.h>

/*
locctr location counter
ol - input optab lines
pl - input pgm lines
strcut ippgm - ip pgm table structure 
struct optab - optab table structure
sadr -  starting address
stflag - symtab check flag
errflag - error flag
sym - symtab counter
pgmlength - program length
*/

int locctr,pl,ol,sadr,stflag=0,errflag=0,sym=0,pgmlength,ifcnt=0;

struct inputpgm
{
	char label[10],opcode[10],operand[10];
}input[25];

struct optab
{
	char opc[10],hex[10];//opcode and hexa code
}opt[20];

struct intermediatefile
{
	int address;
	char label[10],opcode[10],operand[10];
}intfile[20];

struct symtab
{
	char lname[10],ladr[10];//label name and address
}symt[20];

void insertST(char label[],int loc)
{
	symt[sym].lname=label;
	symt[sym].ladr=loc;
}

void pass1()
{
	int i=0;
	if(input[i].opcode="START")
	{
		sadr=input[i].operand;
		locctr=sadr;
		intfile[i].label=input[i].label;
		intfile[i].opcode=input[i].opcode;
		intfile[i].operand=input[i].operand;
		i++;ifcnt++;
	}
	else
		locctr=0;
		
	while(input[i].opcode!="END")
	{
		intfile[i].label=input[i].label;
		intfile[i].opcode=input[i].opcode;
		intfile[i].operand=input[i].operand;
		intfile[i].address=locctr;
		ifcnt++;
		
		if(input[i].label!=NULL)
		{
			int k=0;
			while(symt[k++].lname==input[i].label && k<20)
			{
				stflag=1;
			}
			if(stflag==0)
			{
				errflag=1;
				printf("Duplicate Element\n");
			}
			else
			{
				insertST(input[i].label,locctr);
			}
			
			int topt=0;
			while(opt[topt].opc!=NULL)
			{
				if(opt[topt].opc == input[i].opcode)
					locctr=locctr+3;
				topt++;
			}
			topt=0;
			while(opt[topt].opc!=NULL)
			{
				if(opt[topt].opc == "WORD")
					locctr=locctr+3;
				else if(opt[topt].opc == "RESW")
					locctr=locctr+(3*input[i].operand);
				else if(opt[topt].opc == "RESB")
					locctr=locctr+input[i].operand;
				else if(opt[topt].opc == "BYTE")
					locctr=locctr++;
				else 
					errflag=1;					
				topt++;	
			}
		}
	}
	intfile[i].label=input[i].label;
	intfile[i].opcode=input[i].opcode;
	intfile[i].operand=input[i].operand;
	ifcnt++;
	
	pgmlength=locctr-sadr;
}

void main()
{
	printf("Lines In Input Pgm = ");
	scanf("%d",&pl);
	printf("Enter the Input Program\n");
	for(int i=0;i<pl;i++)
		scanf("%s %s %s",input[i].label,input[i].opcode,input[i].operand);
	
	printf("Lines In OPTAB = ");
	scanf("%d",&ol);
	for(int i=0;i<ol;i++)
		scanf("%s %s",opt[i].opc,opt[i].hex);
		
	pass1();
	printf("\n\n");
	for(int i=0;i<ifcnt;i++)
		printf("%d %s %s %s\n",intfile[i].address,intfile[i].label,intfile[i].opcode,intfile[i].operand);
}


