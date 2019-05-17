#include "pch.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20

int top = -1;
char stack[SIZE];

void push(char x) {
	top++;
	stack[top] = x;
}

void pop(char t) {
	if (t == '}' && stack[top] == '{') top--;
	else if (t == ']' && stack[top] == '[') top--;
	else if (t == ')' && stack[top] == '(') top--;
}

void Display() {
	int i;
	if (top == -1) printf("Stack is empty, balanced parenthesis");
	else {
		printf("Not balanced! You should control -> ");
		for (i = 0; i <= top; i++) printf("%c ", stack[i]);
	}
	printf("\n");
}

int main()
{
	char array[SIZE], x, t;
	int i, len;
	printf("Parenthesis: ");
	gets_s(array, SIZE);
	len = strlen(array);
	printf("\nThe length of your array is %d\n", len);
	
	for (i = 0; i < SIZE; i++) {
		if (array[i] == '{' || array[i] == '[' || array[i] == '(') {
			x = array[i];
			push(x);
		}
		else if (array[i] == '}' || array[i] == ']' || array[i] == ')') {
			t = array[i];
			pop(t);
		}
	}
	Display();
}

