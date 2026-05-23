struct ListNode* merge(struct ListNode* a, struct ListNode* b){
    struct ListNode temp;
    struct ListNode* tail = &temp;
    while(a != NULL && b != NULL){
        if(a->val<=b->val){
            tail->next = a;
            a = a->next;
        }
        else{
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = (a != NULL) ? a:b;
    return temp.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode* prev = NULL;
    struct ListNode* mid = head;
    struct ListNode* nxt = head;

    while(nxt != NULL && nxt->next != NULL){
        prev = mid;
        mid = mid->next;
        nxt = nxt->next->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
    }
    struct ListNode* a = sortList(head);
    struct ListNode* b = sortList(mid);
    return merge(a,b);
}
