#include <stdio.h>
#include <stdlib.h>
#include <stdbool,h>

typedef struct ListNode{
    int data;
    struct ListNode*next;
}ListNode;

bool hasCycle(struct ListNode*head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    struct ListNode*slow = head;
    struct ListNode*fast = head->next;

    while(slow != fast){
        if(fast != NULL || fast->next != NULL){
            return false;
        }
        slow =  slow->next;
        fast = fast->next->next;
    }
    return true;
}