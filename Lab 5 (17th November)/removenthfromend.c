struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) return NULL;
    int len = 0;
    struct ListNode *temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    if (n == len) {
        struct ListNode *newHead = head->next;
        free(head);
        return newHead;
    }
    int k = len - n;  
    temp = head;
    for (int j = 1; j < k; j++) {  
        temp = temp->next;
    }
    struct ListNode *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}