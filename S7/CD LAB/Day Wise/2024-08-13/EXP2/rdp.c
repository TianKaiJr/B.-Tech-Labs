#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>


#define INPUT_STR 100
char ip_str[INPUT_STR];
int str_index = 0;
bool error = false;

void Tdash();
void Edash();
void T();
void F();
char getSubString();

void E() {
    T();
    Edash();
}

void Edash() {
    if (ip_str[str_index] == '+') {
        printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"E' → +TE'");
        str_index++;
        T();
        Edash();
    } else if (ip_str[str_index] == '-') {
        printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"E' → -TE'");
        str_index++;
        T();
        Edash();
    } else{
      printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"E' → ε");
    }
}

void T() {
    F();
    Tdash();
}

void Tdash() {
    if (ip_str[str_index] == '*') {
        printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"T' → *FT'");
        str_index++;
        F();
        Tdash();
    } else if (ip_str[str_index] == '/') {
        printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"T' → /FT'");
        str_index++;
        F();
        Tdash();
    } else{
      printf("|%15s|%10s|\n", getSubString(ip_str,str_index,strlen(ip_str)),"E' → ε");
    }
}

void F() {
    if (isalnum(ip_str[str_index])) {
        while (isalnum(ip_str[str_index])) {
            str_index++;
        }
    } else if (ip_str[str_index] == '(') {
        str_index++;
        E();
        if (ip_str[str_index] == ')') {
            str_index++;
        } else {
            error = true;
        }
    } else {
        error = true;
    }
}

char getSubString(char* str,int start,int end) {
    if (start < 0 || end < start || start >= strlen(str) || end >= strlen(str)) {
        return NULL;
    }
    int length = end - start + 1;
    char* sub = (char*)malloc(length + 1);
    if (sub == NULL) {
        return NULL;
    }
    strncpy(sub, str + start, length);
    sub[length] = '\0';
    return sub;
}

int main() {
    // Read the string to be parsed
    printf("Expression >> ");
    scanf("%s", ip_str);
    printf("|%15s|%10s|\n", "Input", "Action");
    E();
    if (str_index >= strlen(ip_str) && !error) {
        printf("Expression Accepted\n");
    } else {
        printf("Expression Rejected\n");
    }
    return 0;
}
