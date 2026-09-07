#include <stdio.h>
#include <stdlib.h>
#include <string.h>   

typedef struct Node {
    char data;       
    struct Node* next;
} Node;

void push(Node** top, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

char pop(Node** top) {
    if (*top == NULL) {
        printf("栈为空\n");
        return '\0';   // 空字符表示失败
    }
    Node* temp = *top;
    char data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}

char peek(Node* top) {
    if (top == NULL) return '\0';
    return top->data;
}

// 判断括号是否匹配的辅助函数
int isMatch(char left, char right) {
    if (left == '(' && right == ')') return 1;
    if (left == '[' && right == ']') return 1;
    if (left == '{' && right == '}') return 1;
    return 0;
}

// 主函数：判断字符串 s 是否有效
int isValid(char* s) {
    Node* stack = NULL;   // 初始化空栈
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        // 1. 如果是左括号，押入栈
        if (c == '(' || c == '[' || c == '{') {
            push(&stack, c);
        } 
        // 2. 如果是右括号
        else if (c == ')' || c == ']' || c == '}') {
            // 如果栈为空，说明右括号多了，直接返回false
            if (stack == NULL) {
                return 0;
            }
            // 看栈顶是否匹配
            char topChar = peek(stack);
            if (isMatch(topChar, c)) {
                pop(&stack);   // 匹配了就弹出
            } else {
                return 0;      // 不匹配直接失败
            }
        }
    }
    
    // 最后如果栈为空，说明所有括号都匹配了
    return stack == NULL;
}

// 测试
int main() {
    char test1[] = "()[]{}";     // 应该返回 true
    char test2[] = "([)]";       // 应该返回 false
    char test3[] = "{[]}";       // 应该返回 true
    
    printf("%d\n", isValid(test1));  // 输出1
    printf("%d\n", isValid(test2));  // 输出0
    printf("%d\n", isValid(test3));  // 输出1
    
    return 0;
}