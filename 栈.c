#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 定义栈节点结构体
typedef struct Stack {
    int data;
    struct Stack* next;
} Stack;

// ========== 核心操作 ==========

// 1. 入栈（头插法）
void push(Stack** top, int data) {
    // 创建新节点
    Stack* newNode = (Stack*)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("内存分配失败！\n");
        return;
    }
    
    // 初始化新节点
    newNode->data = data;
    newNode->next = *top;  // 新节点指向原来的栈顶
    
    // 更新栈顶指针
    *top = newNode;
    
    printf("入栈成功: %d\n", data);
}

// 2. 出栈（删除头节点）
int pop(Stack** top) {
    // 检查栈是否为空
    if (*top == NULL) {
        printf("栈已空，无法出栈！\n");
        return -1;  // 返回 -1 表示失败
    }
    
    // 保存栈顶节点
    Stack* temp = *top;
    int data = temp->data;  // 保存数据
    
    // 更新栈顶指针
    *top = (*top)->next;
    
    // 释放内存
    free(temp);
    
    printf("出栈成功: %d\n", data);
    return data;
}

// 3. 查看栈顶元素（不出栈）
int peek(Stack* top) {
    if (top == NULL) {
        printf("栈为空，无法查看栈顶！\n");
        return -1;
    }
    return top->data;
}

// ========== 辅助操作 ==========

// 4. 判断栈是否为空
bool isEmpty(Stack* top) {
    return top == NULL;
}

// 5. 获取栈的大小
int size(Stack* top) {
    int count = 0;
    Stack* current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// 6. 打印栈（从栈顶到栈底）
void printStack(Stack* top) {
    if (top == NULL) {
        printf("栈为空\n");
        return;
    }
    
    Stack* current = top;
    printf("栈顶 -> ");
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("-> ");
        }
        current = current->next;
    }
    printf(" <- 栈底\n");
}

// 7. 清空栈
void clearStack(Stack** top) {
    while (*top != NULL) {
        Stack* temp = *top;
        *top = (*top)->next;
        free(temp);
    }
    printf("栈已清空\n");
}

// 8. 释放整个栈（等价于 clearStack）
void freeStack(Stack** top) {
    clearStack(top);
}