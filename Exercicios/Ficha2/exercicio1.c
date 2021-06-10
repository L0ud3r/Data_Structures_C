#include <stdio.h>
#include <stdlib.h>

typedef struct _stack
{
    int value;
    struct _stack *next;
} Stack;


int top(Stack* stack){
    return stack->value;
}

Stack* pop(Stack* stack){
    Stack *aux = stack->next;

    stack->next = NULL;
    free(stack);

    return aux;
}

Stack* push(Stack* stack, int v){
    int counter = 0;
    Stack *new_node = malloc(sizeof(Stack));

    new_node->value = v;
    new_node->next = stack;

    return new_node;
}

void mostraStack(Stack* stack){
    while(stack){
        printf("-> %d\n", stack->value);

        stack = stack->next;
    }
}

Stack* add(Stack* stack){
    int result = stack->value + stack->next->value;
    stack = pop(stack);
    stack = pop(stack);
    stack = push(stack, result);

    return stack;
}

Stack* sub(Stack* stack){
    int result = stack->value - stack->next->value;
    stack = pop(stack);
    stack = pop(stack);
    stack = push(stack, result);

    return stack;
}

int main(){
    Stack* stack = NULL;

    stack = push(stack, 2);
    stack = push(stack, 3);
    stack = push(stack, 4);
    stack = add(stack);
    stack = sub(stack);
    printf("Result: %d\n", top(stack));

    return 0;
}
