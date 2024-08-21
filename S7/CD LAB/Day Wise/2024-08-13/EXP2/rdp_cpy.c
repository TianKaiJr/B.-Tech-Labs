// Recursive Decent Parser of a given grammar
/*
E → TE'
E' → +TE' | ε
T → FT'
T' → *FT' | ε
F → (E) | id
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[10];
int i, error;

void E() {
  T();
  Edash();
}
void Edash() {
  if (input[i] == '+') {
    i++;
    T();
    Edash();
  }
}
void T() {
  F();
  Tdash();
}
void Tdash() {
  if (input[i] == '*') {
    i++;
    F();
    Tdash();
  }
}
void F() {
  if (isalnum(input[i])) i++;
  else if (input[i] == '(') {
    i++;
    E();
    if (input[i] == ')')
      i++;
    else error = 1;
  } else error = 1;
}

void main() {
  i = 0;
  error = 0;
  printf("Enter an arithmetic expression : ");
  gets(input);
  E();
  if (strlen(input) == i && error == 0)
    printf("\nAccepted..!!!\n");
  else printf("\nRejected..!!!\n");
}