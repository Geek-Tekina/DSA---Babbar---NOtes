#include<iostream>
using namespace std;

class node {
    public:
        int data;
        node* next;
};

class stack {
    node* head;
    int size;
    public:
        stack(){
            head = NULL;
            size = 0;
        }
        bool isempty(){
            if(size!=0) return false;
            return true;
        }
        int getSize(){  return size; }
        void push(int val){
            node* temp = new node();
            temp->data = val;
            if (head == NULL)   temp->next = NULL;
            else    temp->next = head;
            head = temp;
            size++;
        }
        void pop(){
            head->next = head;
            size--;
        }
        int top(){
            if(head == NULL) return -1;
            else return head->data;
        }
        void print(){
            node* temp;
            temp = head;
            while(temp!=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    stack s = stack();
    // s.print();
    s.push(10);
    s.push(12);
    s.push(14);
    cout << s.top() << endl;
    cout << s.getSize();
    s.print();
    return 0;
}