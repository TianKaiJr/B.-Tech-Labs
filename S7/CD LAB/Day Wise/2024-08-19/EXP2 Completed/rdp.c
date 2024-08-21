#include <stdio.h>
#include <string.h>

/*
E -> T E'
E' -> + T E' | - T E' | $
T -> F T'
T' -> * F T' | / F T' | $
F -> ( E ) | i
*/

int E(), Edash(), T(), Tdash(), F();

const char *cursor;
char string[64];

int main() {
	printf("String >> ");
	scanf("%s", string); 
	cursor = string;
	printf("|%-20s|%-20s|\n","Input","Action");

	if (E() && *cursor == '\0') { 
		printf(">>> Parsing Success\n");
		return 0;
	} 
	else {
		printf(">>> Parsing Failed\n");
		return 1;
	}
}

int E() {
	printf("|%-20s|%-20s|\n",cursor,"E -> T E'");
	if (T()) { 
		if (Edash())
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}

int Edash() {
	if (*cursor == '+') {
		printf("|%-20s|%-20s|\n",cursor,"E' -> + T E'");
		cursor++;
		if (T()) {
			if (Edash())
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} else if (*cursor == '-') {
		printf("|%-20s|%-20s|\n",cursor,"E' -> - T E'");
		cursor++;
		if (T()) {
			if (Edash())
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	}
	else {
		printf("|%-20s|%-20s|\n",cursor,"E' -> $");
		return 1;
	}
}

int T() {
	printf("|%-20s|%-20s|\n",cursor,"T -> F T'");
	if (F()) { 
		if (Tdash()) 
			return 1;
		else
			return 0;
	} 
	else
		return 0;
}

int Tdash() {
	if (*cursor == '*') {
		printf("|%-20s|%-20s|\n",cursor,"T' -> * F T'");
		cursor++;
		if (F()) {
			if (Tdash())
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} else if (*cursor == '/') {
		printf("|%-20s|%-20s|\n",cursor,"T' -> / F T'");
		cursor++;
		if (F()) {
			if (Tdash())
				return 1;
			else
				return 0;
		} 
		else
			return 0;
	} 
	else {
		printf("|%-20s|%-20s|\n",cursor,"T' -> $");
		return 1;
	}
}

int F() {
	if (*cursor == '(') {
		printf("|%-20s|%-20s|\n",cursor,"F -> ( E )");
		cursor++;
		if (E()) { 
			if (*cursor == ')') {
				cursor++;
				return 1;
			} 
			else
				return 0;
		} 
		else
			return 0;
	} 
	else if (*cursor == 'i') {
		printf("|%-20s|%-20s|\n",cursor,"F -> i");
		cursor++;
		return 1;
	} 
	else
		return 0;
}

