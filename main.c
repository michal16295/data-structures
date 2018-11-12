// C program to evaluate value of a postfix
// expression having multiple digit operands
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
//NODE STRUCT
struct node
{
	char data;
	struct node* next;
};
typedef struct node node;
//STACK STRUCT
struct stack {
	node* head;
};
typedef struct stack t_stack;
//CREATING A STACK
t_stack* create()
{
	t_stack* stack = (t_stack*)malloc(sizeof(t_stack));
	stack->head = NULL;
	return stack;
}
int isEmpty(t_stack* stack)
{
	return stack->head == NULL;
}
//PUSHING AN ELEMENT TO THE FIRST PLACE IN THE STACK
void push(t_stack* stack, char element)
{
	node* temp = (node*)malloc(sizeof(node));
	temp->data = element;
	temp->next = NULL;
	if (isEmpty(stack)) {
		stack->head = temp;
	}
	else {
		temp->next = stack->head;
		stack->head = temp;
	}
}
//POPING THE FIRST ELEMENT FROM THE STACK
char pop(t_stack* stack)
{
	if (!isEmpty(stack)) {
		char element = stack->head->data;
		node* temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
		return element;
	}
	else {
		printf("Stack Underflow\n");
		return 0;
	}
}
char peek(t_stack* stack)
{
	if (!isEmpty(stack)) {
		return stack->head->data;
	}
	else {
		printf("Stack Underflow\n");
		return 0;
	}
}
//PRINTING THE STACK
void display(t_stack* stack)
{
	node* temp = stack->head;
	while (temp != NULL) {
		printf("%c->", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");

}
int isOperator(char token) {
	if (token == '+' || token == '-' || token == '/' || token == '*' || token == '^') return 1;
	return 0;
}
// The main function that returns value
// of a given postfix expression

//CALCULATING 
int evaluatePostfix(char* exp) {
	t_stack* stack = create();
	char token, next_token;
	int result = 0;
	char x, y;
	for (int i = 0; exp[i] != '\0'; i++) {
		 token = exp[i];
		 next_token = exp[i + 1];
		 if (isOperator(next_token)) {
			 // POP TWO ELEMENTS
			 //CONVERT TO NUMBERS
			 //CONVERT THE OPERTOR
			 //CALCULTE
			 //CONVERT TO CHAR
			 //PUSH TO THE STACK
		 }
		 else {
			 if(next_token == ' '){
				 push(stack, token);

			 }
			 
		 }
		 
	}
	return 0;
}
//CHECKING WHICH OPERATOR IS GREATERT
int CheckOpertator(char s_stack, char t_token) {
	if (s_stack == '^') {
		if (s_stack != t_token) {
			return 0;
		}
	}
	else if (s_stack == '*' || s_stack == '/') {
		if (t_token == '+' || t_token == '-') {
			return 0;
		}
	}
	return 1;
}

// CONVERTING FROM INFIX TO POSTFIX
void infixTopostfix(char infix[], char postfix[]) {
	char str[100] = { 0 };
	char token;
	int j = 0;
	t_stack* stack = create();
	for (int i = 0; infix[i] != '\0'; ++i) {
		token = infix[i];
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
		else if (isOperator(token))
		{
			while (!isEmpty(stack) && peek(stack) != '(') {
				if (!CheckOpertator(peek(stack), token)) {
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
	char ex[][50] = { "10*5-3", "(5-2)*13", "18-3*5", "4*5-2", "(10+3)*2", "20-3*5", "12-12/3", "(7+4)^2",
		"(4*5)^2", "(15-7)-4*(18-30)^2", "(23-2)*2^4" };

	for (int i = 0; i < 11; i++) {
		PrintExpDetails(ex[i]);
	}

	return 0;
}
