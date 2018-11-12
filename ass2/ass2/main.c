// C program to evaluate value of a postfix
// expression having multiple digit operands

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>


struct node
{
	char data;
	struct node* next;
};
typedef struct node node;

struct stack
{
	node * head;
};
typedef struct stack t_stack;

int checkOperator(char a, char b) {
	if (a == '^') {
		if (a != b) {
			return 0;
		}
	}
	else if (a == '*' || a == '/') {
		if (b == '+' || b == '-') {
			return 0;
		}
	}
	return 1;
}

t_stack* create()
{
	t_stack* stack = malloc(sizeof(t_stack));
	stack->head = NULL;
	return stack;
}
int isEmpty(t_stack* stack)
{
	return stack->head == NULL;
}
void push(t_stack* stack, char element)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = element;
	n->next = NULL;
	if (isEmpty(stack)) {
		stack->head = n;
	}
	else {
		n->next = stack->head;
		stack->head = n;
	}
}
char pop(t_stack* stack)
{
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		return 0;
	}
	else {
		char c = stack->head->data;
		node* n = stack->head;
		stack->head = stack->head->next;
		free(n);
		return c;
	}
}
char peek(t_stack* stack)
{
	if (isEmpty(stack)) {
		printf("Stack Underflow\n");
		return 0;
	}
	
	return stack->head->data;
}
void display(t_stack * stack)
{
	node* temp = stack->head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
// The main function that returns value
// of a given postfix expression
int evaluatePostfix(char* exp)
{
	// ENTER YOU CODE HERE
	return 0;
}

void infixTopostfix(char infix[], char postfix[]) {
	// CONVERTING FROM INFIX TO POSTFIX
	char str[100] = { 0 };
	t_stack* stack = create();
	int j = 0;
	for (int i = 0; infix[i] != '\0'; ++i) {
		char token = infix[i];
		char next_token = infix[i + 1];
		if (token == '(') {
			push(stack, token);
		}
		else if (token == ')') {
			while (!isEmpty(stack) && peek(stack) != '(') {
				str[j++] = pop(stack);
				str[j++] = ' ';
			}
			pop(stack);
		}
		else if (token == '+' || token == '-' || token == '*' || token == '/' || token == '^') {
			while (!isEmpty(stack) && peek(stack) != '(') {
				if (!checkOperator(peek(stack), token)) {
					str[j++] = pop(stack);
					str[j++] = ' ';
				}
				else break;
			}
			push(stack, token);
		}
		else if (token >= '0' && token <= '9') {
			str[j++] = token;
			if (next_token < '0' || next_token > '9') {
				str[j++] = ' ';
			}
		}
	}
	while (!isEmpty(stack)) {
		str[j++] = pop(stack);
		str[j++] = ' ';
	}

	for (int i = 0; i < j; ++i) {
		*(postfix + i) = str[i];
	}
	postfix[j] = '\n';
}

void PrintExpDetails(char exp[]) {
	char sol[100] = { 0 };
	infixTopostfix(exp, sol);
	printf("Infix expresion: %s\n", exp);
	printf("Postfix expression: %s\n", sol);
	printf("It's Value: %d\n", evaluatePostfix(sol));
	printf("***********************************\n");
}

// Driver program to test the above functions
int main()
{
	t_stack* stack = create();
	for (char i = 1; i <= 10; i++) {
		push(stack, i);
	}
	display(stack);

	pop(stack);
	display(stack);

	char ex[][50] = { "10*5-3", "(5-2)*13", "18-3*5", "4*5-2", "(10+3)*2", "20-3*5", "12-12/3", "(7+4)^2",
		"(4*5)^2", "(15-7)-4*(18-30)^2", "(23-2)*2^4" };

	for (int i = 0; i < 11; i++)
		PrintExpDetails(ex[i]);

	char c;
	scanf("%c", &c);

	return 0;
}
