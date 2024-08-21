/*

Algorithm Shift-Reduce Parser:

1. Initialize:
   - Stack: an empty stack
   - Input: a list of tokens from the input string
   - Production Rules: a list of grammar production rules

2. While Input is not empty or Stack can be reduced:
   - If the top of the stack matches the right-hand side of a production rule:
     - Apply the production rule to the stack
     - Replace the matched symbols on the stack with the left-hand side of the production rule
     - Continue with the next iteration

   - If no reduction is possible and the input is not empty:
     - Shift the next token from the Input onto the Stack
     - Continue with the next iteration

3. End of Input Processing:
   - If Stack contains the start symbol and Input is empty:
     - Parsing is successful, accept the input
   - Otherwise:
     - Parsing fails, reject the input

4. Output:
   - Print the result of the parsing (success or failure)

*/

#include <stdio.h>
#include <string.h>

#define SIZE 100
#define PSIZE 50

char stack[SIZE][50];
char input[SIZE];
char token[50];

struct rules {
    char LHS[PSIZE];
    char RHS[PSIZE];
} productions[SIZE];

int match_rule(int top, char *rhs) {
    int len = strlen(rhs);
    if (len > top) return 0;
    for (int i = 0; i < len; i++) {
        if (strcmp(stack[top - len + i], &rhs[i * 50]) != 0) return 0;
    }
    return 1;
}

void apply_rule(int top, char *lhs) {
    int len = strlen(lhs);
    for (int i = top - len + 1; i <= top; i++) {
        strcpy(stack[i], "");
    }
    strcpy(stack[top - len + 1], lhs);
}

void parser() {
    int top = 0; 
    int input_pos = 0; 
    int num_productions = 0;


    strcpy(stack[top], "$"); 
    strcat(input, "$"); 
    
    printf("@@@@@@@@@@@@@");
    
    while (strcmp(stack[top], "$") != 0 || strcmp(input + input_pos, "$") != 0) {
        for (int i = 0; i < num_productions; i++) {
            int len_rhs = strlen(productions[i].RHS);
            if (match_rule(top, productions[i].RHS)) {
                apply_rule(top, productions[i].LHS);
                top = strlen(stack[top]) - 1;
                break;
            }
        }
        if (strcmp(stack[top], "$") != 0 && strcmp(input + input_pos, "$") != 0) {
            strcpy(stack[++top], &input[input_pos]);
            input_pos += strlen(input + input_pos) + 1;
        }
    }
    if (strcmp(stack[0], "S") == 0 && strcmp(input + input_pos, "$") == 0) {
        printf(">>> Parsing Success\n");
    } else {
        printf(">>> Parsing Failed\n");
    }
}

int main() {
    int num_productions;

    printf("Number of Production Rules >> ");
    scanf("%d", &num_productions);
    getchar(); 
    
    
    printf("Production Rules (format: LHS->RHS)\n");
    for (int i = 0; i < num_productions; i++) {
        printf("Rule %d: ", i + 1);
        if (fgets(token, sizeof(token), stdin) != NULL) {
            token[strcspn(token, "\n")] = '\0';
            sscanf(token, "%[^->]->%s", productions[i].LHS, productions[i].RHS);
        }
    }

    printf("Input String >>> ");
    scanf("%s", input);
	printf("@@@@@@@@@@@@@");
    parser();    

    return 0;
}


