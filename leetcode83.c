struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;

    struct ListNode* cur = head;
 
    while (cur != NULL && cur->next != NULL) {
        if (cur->val == cur->next->val) {
            cur->next = cur->next->next;
        } else {
            cur = cur->next;
        }
    }
    
    return head;
}