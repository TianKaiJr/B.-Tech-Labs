#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

FILE *table;

// Check if character is a delimiter
bool isDelimiter(char ch, char *pun) {
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
        ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' ||
        ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}') {
    // printf("%c",ch);
        char chStr[2] = {ch, '\0'};
        if (strlen(pun) > 0 /*&& ch != ' '*/) {
            strcat(pun, ",");
        }
        strcat(pun, chStr);
        return true;
    }
    return false;
}

// Check if string is a keyword
bool isKeyword(const char* str) {
    const char* keywords[] = {
        "int","scanf","printf","#include"
    };
    for (int i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) return true;
    }
    return false;
}

// Check if character is an operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' ||
           ch == '<' || ch == '=';
}

// Check if string is a valid identifier
bool isValidIdentifier(const char* str) {
    if (isKeyword(str)) return false;
    if (!str || !str[0] || !isalpha(str[0])) return false;
    for (int i = 1; str[i]; i++) {
        if (!isalnum(str[i]) && str[i] != '_') return false;
    }
    return true;
}

// Check if string is an integer
bool isInteger(const char* str) {
    if (str[0] == '-' && !str[1]) return false;
    for (int i = (str[0] == '-' ? 1 : 0); str[i]; i++) {
        if (!isdigit(str[i])) return false;
    }
    return true;
}

// Check if string is a real number
bool isReal(const char* str) {
    bool hasDecimal = false;
    if (str[0] == '-' && !str[1]) return false;
    for (int i = (str[0] == '-' ? 1 : 0); str[i]; i++) {
        if (str[i] == '.') {
            if (hasDecimal) return false;
            hasDecimal = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return hasDecimal;
}

//check for format specifiers
bool isFormatSpecifier(const char *str) {
    const char *FIDs[] = {"\"%d","%d\"", "%s"};  
    size_t numFIDs = sizeof(FIDs) / sizeof(FIDs[0]);  
    for (size_t i = 0; i < numFIDs; i++) {
        if (strcmp(str, FIDs[i]) == 0) {
            return true;
        }
    }
    return false;
}

//header files
bool isHeaderFile(const char*str){
    const char *headerFiles[] = {"stdio.h"};  
    size_t numHFs = sizeof(headerFiles) / sizeof(headerFiles[0]);  
    for (size_t i = 0; i < numHFs; i++) {
        if (strcmp(str, headerFiles[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Extract substring
char* subString(const char* str, int left, int right) {
    char* subStr = malloc(sizeof(char) * (right - left + 2));
    strncpy(subStr, str + left, right - left + 1);
    subStr[right - left + 1] = '\0';
    return subStr;
}

// Parse a single line
void parse(const char *str) {
    char kws[MAX] = "", ids[MAX] = "", lit[MAX] = "", ops[MAX] = "", pun[MAX] = "";
    int left = 0, right = 0, len = strlen(str);

    while (right <= len) {
        char temp[MAX];
        if (isDelimiter(str[right],pun)) {
            if (left < right) {
                char* subStr = subString(str, left, right - 1);
                if (isKeyword(subStr)) {
                    snprintf(temp, sizeof(temp), "%s,", subStr);
                    strcat(kws, temp);
                } else if (isInteger(subStr) || isReal(subStr)) {
                    snprintf(temp, sizeof(temp), "%s,", subStr);
                    strcat(lit, temp);
                } else if (isValidIdentifier(subStr)) {
                    snprintf(temp, sizeof(temp), "%s,", subStr);
                    strcat(ids, temp);
                } else {
                    if(isFormatSpecifier(subStr) || isHeaderFile(subStr)){
                        snprintf(temp, sizeof(temp), "%s,", subStr);
                        strcat(lit, temp);
                    }
                }
                free(subStr);
            }
            if (isOperator(str[right])) {
                snprintf(temp, sizeof(temp), "%c,", str[right]);
                strcat(ops, temp);
            }

            right++;
            left = right;
        } else {
            right++;
        }
    }

    fprintf(table, "|0000|%15s|%15s|%15s|%15s|%15s|\n", kws, ids, lit, ops, pun);
}

int main() {
    FILE *code = fopen("code.c", "r");
    if (code == NULL) {
        printf("Code file not found!\n");
        return 1;
    }

    table = fopen("table.txt", "w");
    if (table == NULL) {
        printf("Failed to open table file!\n");
        fclose(code);
        return 1;
    }

    fprintf(table, "|%4s|%15s|%15s|%15s|%15s|%15s|\n","LINE","KEYWORDS","IDENTIFIERS","LITERALS","OPERATORS","PUNCTUATORS");

    char read[MAX];
    while (fgets(read, sizeof(read), code) != NULL) {
        parse(read);
    }

    fclose(table);
    fclose(code);
    return 0;
}