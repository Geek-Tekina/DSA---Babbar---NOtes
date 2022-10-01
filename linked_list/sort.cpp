ListNode* merge(ListNode* left, ListNode* right){
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    ListNode *ans = new ListNode(-1);
    ListNode* temp = ans;
    while(left!=NULL && right!=NULL){
        if(left->val < right->val){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else{
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }
    if(left!=NULL){
            temp->next = left;
            temp = left;
            left = left->next;
    }
    if(right!=NULL){
            temp->next = right;
            temp = right;
            right = right->next;
        }
    return ans->next;
}

ListNode* sortList(ListNode* head) {
    if(!head || !head->next)
        return head;
    ListNode *slow=head, *fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *left = head;
    ListNode *right = slow->next;
    slow->next = NULL;
    
    left = sortList(left);
    right = sortList(right);
    
    ListNode* result = merge(left, right);
    return result;
}