struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode*node = &dummy;
    while(node->next != NULL){
        if (node->next->val == val){
            struct ListNode*ToDelete = node->next;
            node->next = node->next->next;
            free(ToDelete);
        }else{
            node = node->next;
        }
    }
    return dummy.next;
}