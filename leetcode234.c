struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur != NULL) {
        struct ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    // 改这里：快指针先看两步
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    struct ListNode* secondHalf = reverseList(slow->next);
    struct ListNode* firstHalf = head;
    struct ListNode* second = secondHalf;
    
    while (second != NULL) {
        if (firstHalf->val != second->val) {
            return false;
        }
        firstHalf = firstHalf->next;
        second = second->next;
    }
    
    slow->next = reverseList(secondHalf);
    return true;
}