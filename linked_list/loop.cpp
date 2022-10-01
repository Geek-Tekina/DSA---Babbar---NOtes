class Solution {
public:
    bool tortoiseFare(ListNode *head) {
        ListNode *slow = head, *fast = head;
        // if the ll has cycle then this loop will never end
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            // sooner or later this will come true
            if (slow == fast) return true;
        }
        return false;
    }

    bool setMethod(ListNode *head){
        // not just value instead whole node is stored
        // fast but extra space is required 
        unordered_set<ListNode*> s;
        while(head){
            if(s.find(head)!=s.end()) return true;
            s.insert(head);
            head=head->next;
        }
        return false;
    }

};