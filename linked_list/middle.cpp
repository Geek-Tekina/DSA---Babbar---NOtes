#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;   
    }

    ListNode* delmiddleNode(ListNode* head) {
        auto dummy = new ListNode(), t1 = dummy, t2 = head;
        dummy -> next = head;
        
        while (t2 and t2 -> next) {
            t1 = t1 -> next;
            t2 = t2 -> next -> next;
        }
        
        t1 -> next = t1 -> next -> next;
        
        return dummy -> next;
    }
};

