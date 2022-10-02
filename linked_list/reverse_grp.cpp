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
    ListNode* curr=head;
    ListNode* prev=NULL,*nxt=NULL;
    ListNode* temp=head;

    int c=k;
    while(temp!=NULL && c>0){
        temp=temp->next;    c--;
    }
    if(c>0) return head;
    else    c=k;

    while(curr!=NULL && c>0) {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
        c--;
    }

    if(nxt!=NULL)   head->next=reverseKGroup(nxt,k);
    return  prev;
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