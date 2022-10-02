class Solution {
public:

/*
- Modification Method : traverse each linked list and point them to null, 
    if you come again on a node which is already pointing to null, 
    then that is where loop begins, 
    in case array turn the positive integers in negative and 
    if you come accross a negative integer then it is duplicated.
- Extra Space Method : use unordered_set to store the nodes
- Optimised Method : Use Floyd'd tortoise and hare algorithm
    to detect cycle. It is kind of Two pointer approach, 
    as one pointer is moving 1 at a time and another is moving 2 at a time.
*/

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