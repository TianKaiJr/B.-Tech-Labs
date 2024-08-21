#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 20

char digit[MAX_SIZE][20];
int digiti = 0;

char string[MAX_SIZE][50];
int stringi = 0;

char keyword[MAX_SIZE][10];
int keywordi = 0;

char operator[MAX_SIZE][2];  
int operatori = 0;

char punctuator[MAX_SIZE][2];  
int punctuatori = 0;

char identifier[MAX_SIZE][10];
int identifieri = 0;

bool isValidDelimiter(char ch) {
    return (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' || ch == '=' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}' || 
            ch == '\n' || ch == '&');
}

bool isKeyword(const char* str) {
    const char *keywords[] = {
        "if", "else", "while", "do", "break", "continue",
        "int", "double", "float", "return", "char", "void",NULL
    };
    
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '>' || ch == '<' || ch == '=' || ch == '&');
}

bool isPunctuator(char ch) {
    return (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}');
}

void readfile(const char *filename) {
    FILE *fptr = fopen(filename, "r");
    if (!fptr) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char a[50];
    char ch = fgetc(fptr);

    while (ch != EOF) {
        strcpy(a, "");
        while (!isValidDelimiter(ch) && ch != EOF) {
            if (ch == '"') {
                strncat(a, &ch, 1);
                ch = fgetc(fptr);
                while (ch != '"' && ch != EOF) {
                    strncat(a, &ch, 1);
                    ch = fgetc(fptr);
                }
                if (ch == '"') {
                    strncat(a, &ch, 1);
                }
                strcpy(string[stringi++], a);
                strcpy(a, "");
                break;
            }
            strncat(a, &ch, 1);
            ch = fgetc(fptr);
        }

        if (strcmp(a, "")) {
            if (isdigit(a[0])) {
                strcpy(digit[digiti++], a);
            } else if (!isKeyword(a)) {
                strcpy(identifier[identifieri++], a);
            }
        }

        if (isKeyword(a)) {
            strcpy(keyword[keywordi++], a);
        }

        if (isOperator(ch)) {
            snprintf(operator[operatori], sizeof(operator[operatori]), "%c", ch);
            operatori++;
        }

        if (isPunctuator(ch)) {
            snprintf(punctuator[punctuatori], sizeof(punctuator[punctuatori]), "%c", ch);
            punctuatori++;
        }

        ch = fgetc(fptr);
    }

    fclose(fptr);
}

void print_string() {
    printf("\nLITERALS: ");
    for (int i = 0; i < stringi; i++) {
        printf("%s, ", string[i]);
    }
    printf("\n");
}

void print_digit() {
    printf("NUMERICS: ");
    for (int i = 0; i < digiti; i++) {
        printf("%s, ", digit[i]);
    }
    printf("\n");
}

void print_operator() {
    printf("OPERATORS: ");
    for (int i = 0; i < operatori; i++) {
        printf("%s, ", operator[i]);
    }
    printf("\n");
}

void print_punctuator() {
    printf("PUNCTUATORS: ");
    for (int i = 0; i < punctuatori; i++) {
    
        printf("%s, ", punctuator[i]);
    }
    printf("\n");
}

void print_keyword() {
    printf("KEYWORDS: ");
    for (int i = 0; i < keywordi; i++) {
    
        printf("%s, ", keyword[i]);
    }
    printf("\n");
}

void print_identifier() {
    printf("IDENTIFIERS: ");
    for (int i = 0; i < identifieri; i++) {
        printf("%s, ", identifier[i]);
    }
    printf("\n");
}

int main() {
    char filename[100];  
    printf("Enter filename: ");
    scanf("%99s", filename); 

    readfile(filename);
    print_string();
    print_digit();
    print_operator();
    print_keyword();
    print_punctuator();
    print_identifier();

    return 0;
}

