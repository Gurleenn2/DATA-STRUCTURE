#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (!newStack) {
        printf("Memory error\n");
        return NULL;
    }
    newStack->top = NULL;
    return newStack;
}
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->next = stack->top;
        stack->top = newNode;
    }
    printf("Pushed element: %d\n", data); 
}
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    int data = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("Popped element: %d\n", data);  
    return data;
}

void printStack(Stack* stack) {
    Node* temp = stack->top;
    printf("Stack: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    Stack* stack = createStack();
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);

    printStack(stack);

    pop(stack);
    pop(stack);

    printStack(stack);
    return 0;
}
