#include <iostream>
#include <vector>
using namespace std;

class ListNode {
    public:
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* solve(ListNode* head, int k){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* groupHead;
    int counter = 0;
    while(curr){
        counter = 0;
        groupHead = curr;
        while(curr && counter < k){
            groupHead->next = curr->next->next;
        }
    }
    return NULL;
}

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    ListNode* thead = head;
    while(thead){
        cout << thead->val << " ";
        thead = thead->next;
    } 
    ListNode* rev = solve(head, 3);
    while(rev){
        cout << rev->val << " ";
        rev = rev->next;
    } 
    return 0;
}