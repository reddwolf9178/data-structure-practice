#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>   // 题目里用了 bool，必须加这个

// 第一步：你的“私人工厂”（全部写在题目模板上面）
typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

void push(Stack** top, int data) {
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(Stack** top) {
    Stack* temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

int peek(Stack* top) {
    return top->data;
}

typedef struct {
    Stack* in;
    Stack* out;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->in = NULL;
    obj->out = NULL;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->in, x);   
}

int myQueuePop(MyQueue* obj) {
    if (obj->out == NULL) {
        while (obj->in != NULL) {
            int val = pop(&obj->in);   
            push(&obj->out, val);
        }
    }
    return pop(&obj->out);
}

int myQueuePeek(MyQueue* obj) {
    if (obj->out == NULL) {
        while (obj->in != NULL) {
            int val = pop(&obj->in);
            push(&obj->out, val);
        }
    }
    return peek(obj->out);
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->in == NULL && obj->out == NULL;
}

void myQueueFree(MyQueue* obj) {
    while (obj->in != NULL) pop(&obj->in);
    while (obj->out != NULL) pop(&obj->out);
    free(obj);
}