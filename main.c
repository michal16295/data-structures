// C program to evaluate value of a postfix
// expression having multiple digit operands
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
typedef struct node* node;
node create(node head)
{
    return head = NULL;
}
int isEmpty(node head)
{
    return head == NULL ? 1 : 0;
}
node push(node head,int element)
{
    if(isEmpty(head)){
        head = (node)malloc(sizeof(node));
        head ->data = element;
        head->next = NULL;
    }
    else{
        node temp = (node)malloc(sizeof(node));
        temp->data = element;
        temp->next = head;
        head = temp;
    }
    return head;
}
node pop(node head)
{
    if(isEmpty(head)){
        printf("Stack Underflow\n");
        return NULL;
    }
    else{
        node temp = head;
        head = head->next;
        return temp;
    }
}
void display(node head)
{
    while(head != NULL){
        printf("%d->" , head->data);
        head = head->next;
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
    char str[] = "";
    node stack = NULL;
    char token;
    int j = 0;
    stack = create(stack);
    for(int i = 0  ; infix[i] != '\0' ; i++){
        token = infix[i];
        if(token == '('){
            stack = push(stack,token);
        }
        if(token == ')'){
            while(stack->data != '('){
                str[j] = stack->data;
                stack = pop(stack);
                j++;
            }
            stack = pop(stack);
        }
        if(token == '+' || token == '-' || token == '*' || token == '/' || token == '^'){
            while(stack->data != '+' || stack->data != '-'){
                stack = pop(stack);
            }
            
        }
    }
    
    
}

void PrintExpDetails(char exp[]){
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
    node head = NULL;
    head = create(head);
    for(int i = 0 ; i < 10 ; i++){
        head = push(head,i);
    }
    display(head);
    node head2 = NULL;
    for(int i = 0 ; i < 5 ; i++){
        head2 = push(head2 , i);
    }
    head = pop(head);
    head2 = pop(head2);
    display(head2);
    
   /*char ex[][50] = { "10*5-3", "(5-2)*13", "18-3*5", "4*5-2", "(10+3)*2", "20-3*5", "12-12/3", "(7+4)^2",
        "(4*5)^2", "(15-7)-4*(18-30)^2", "(23-2)*2^4" };
    
    for (int i = 0; i < 11; i++)
        PrintExpDetails(ex[i]);*/
    
    return 0;
}
