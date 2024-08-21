//Lexical Analyzer in C
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct tokens_table
{
	char keywords[100];
	char identifier[100];
	char number[100];
	char punctuator[100];
	char literal[100];
	char operator[100];
}table[MAX];

//check delimits
bool isDelimiter(char ch)
{
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}

//keyword checking
bool isKeyword(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") ||
!strcmp(str, "while") || !strcmp(str, "do") ||!strcmp(str, "break") ||!strcmp(str, "continue") || !strcmp(str, "int")|| !strcmp(str, "double")|| !strcmp(str, "float")|| !strcmp(str, "return") || !strcmp(str, "char")|| !strcmp(str, "case") || !strcmp(str, "char")|| !strcmp(str, "sizeof") || !strcmp(str, "long")|| !strcmp(str, "short") || !strcmp(str, "typedef")|| !strcmp(str, "switch") || !strcmp(str,"unsigned")|| !strcmp(str, "void") || !strcmp(str, "static")|| !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

//check operator
bool isOperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=')
        return (true);
    return (false);
}

//check validity
bool validIdentifier(char* str)
{
	if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") || !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int") || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str, "char") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "sizeof") || !strcmp(str, "switch") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

//check Integer
bool isInteger(char* str)
{
	int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}

//check RealNumber
bool isReal(char* str)
{
	int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}

//extract SubString
char* subString(char* str,int left,int right)
{
	int i;
    char* subStr = (char*)malloc(
                  sizeof(char) * (right - left + 2));
 
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}

//parse one line
void parse(char *str)
{
	int left=0,right=0;
	int len=strlen(str);
	
	while(right<=len && left<=right)
	{
		if(isDelimiter(str[right])==false)
			right++;
		
		if (isDelimiter(str[right]) == true && left == right) {
            if (isOperator(str[right]) == true)
                printf("'%c' IS AN OPERATOR\n", str[right]);
 
            right++;
            left = right;
        } else if (isDelimiter(str[right]) == true && left != right
                   || (right == len && left != right)) {
            char* subStr = subString(str, left, right - 1);
 
            if (isKeyword(subStr) == true)
                printf("'%s' IS A KEYWORD\n", subStr);
 
            else if (isInteger(subStr) == true)
                printf("'%s' IS AN INTEGER\n", subStr);
 
            else if (isReal(subStr) == true)
                printf("'%s' IS A REAL NUMBER\n", subStr);
 
            else if (validIdentifier(subStr) == true
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS A VALID IDENTIFIER\n", subStr);
 
            else if (validIdentifier(subStr) == false
                     && isDelimiter(str[right - 1]) == false)
                printf("'%s' IS NOT A VALID IDENTIFIER\n", subStr);
            left = right;
        }
    }
    return;
}

void main()
{
	FILE *code,*table;
	char read[100],write[100];
	
	code=fopen("code.c","r");
	
	if(code==NULL)
		printf("Code_File Not Found!!\n");
	else
	{
		table=fopen("table.txt","w");
		while(fgets(read,sizeof(read),code)!=NULL)
		{	
			//Parsing and Checking
			parse(read);
			
			/*printf("%s",read);
			fprintf(table,"%s",read);*/
		}
		fclose(table);
		fclose(code);
	}	
}
