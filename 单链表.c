#include <stdio.h>
#include <stdlib.h>
//定义单链表节点结构体
typedef struct Node {
    int data; //数据域
    struct Node* next; //指针域
}Node;
Node*createNode(int data){
    Node*newNode = (Node*)malloc(sizeof(Node)); //分配内存
    //检测内存是否分配
    if (newNode ==  NULL){
        printf("内存分配失败\n");
        return NULL;
    }
    //初始化数据和指针
    newNode->data = data;
    newNode->next = NULL;
    //返回新节点的地址
    return newNode;
}
//头插法
void insertHead(Node**head,int data){
    Node*newNode = (Node*)malloc(sizeof(Node)); //分配内存
    //检测内存是否分配
    if (newNode ==  NULL){
        printf("内存分配失败\n");
        return;
    }
    newNode->data = data;//初始化新节点
    newNode->next = *head;//新节点指向头指针
    *head = newNode;//更新头指针
}
//尾插法
void insertTail(Node**head,int data){
    Node*newNode = (Node*)malloc(sizeof(Node)); //分配内存
    //检测内存是否分配
    if (newNode ==  NULL){
        printf("内存分配失败\n");
        return;
    }
    //初始化
    newNode->data = data;
    newNode->next = NULL;
    //若链表为空，则新节点为头节点
    if (*head == NULL){
        *head = newNode;
        return;
    }
    //遍历到最后一个节点
    Node*current = *head;
    while (current->next != NULL){
        current = current->next;
    }
    //最后节点后继指向新节点
    current->next = newNode;

}
//删除指定值
void deleteNode(Node**head,int target){
    //空链表检查
    if (*head ==  NULL){
        printf("链表为空\n");
        return;
    }
    Node*current = *head;
    Node*prev = NULL;
    //查找目标节点
    while (current != NULL && current->data != target){
        prev = current;
        current = current->next;
    }
    //未找到目标值
    if (current == NULL){
        printf("未找到值%d\n",target);
        return;
    }
    //删除节点
    if (prev == NULL){
        //删除的是头节点
        *head = current->next;
    }else{
        //删除的是中间节点或尾节点
        prev->next = current->next;
    }
    free(current);
    printf("成功删除%d\n",target);               
}
//打印链表
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}