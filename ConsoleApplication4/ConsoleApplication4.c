#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// Function to convert a string to lowercase
void toLowercase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a character is an English alphabet
int isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to remove non-alphabet characters from a string
void removeNonAlpha(char* str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isAlpha(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to implement a stack
void push(Stack* stack, element data) {
    if (stack->top < MAX_STACK_SIZE) {
        stack->data[stack->top++] = data;
    }
}

element pop(Stack* stack) {
    if (stack->top > 0) {
        return stack->data[--stack->top];
    }
    return -1; // Error: stack is empty
}

// Function to implement a queue
void enqueue(QueueType* queue, element data) {
    if (queue->rear < MAX_QUEUE_SIZE) {
        queue->data[queue->rear++] = data;
    }
}

element dequeue(QueueType* queue) {
    if (queue->front < queue->rear) {
        return queue->data[queue->front++];
    }
    return -1; // Error: queue is empty
}

// Function to check if a string is a palindrome
int isPalindrome(char* str) {
    Stack stack;
    stack.top = 0;
    QueueType queue;
    queue.front = queue.rear = 0;

    for (int i = 0; str[i]; i++) {
        push(&stack, str[i]);
        enqueue(&queue, str[i]);
    }

    while (stack.top > 0) {
        if (pop(&stack) != dequeue(&queue)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    int choice;
    char inputStr[100];

    while (1) {
        printf("1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("14: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printf("회문을 입력하세요: ");
            scanf("%[^\n]s", inputStr);
            toLowercase(inputStr);
            removeNonAlpha(inputStr);
            break;
        case 2:
            if (isPalindrome(inputStr)) {
                printf("회문입니다.\n");
            }
            else {
                printf("회문이 아닙니다.\n");
            }
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}