#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};

class queue{
    node* front; 
    node* rear;
    int size;
    public:
        queue(){
            front = NULL; 
            rear = NULL;
            size = 0;
        }
        int getSize(){  return size; }
        void getFR(){
            if(front == NULL)   cout << "NULL\n";
            else if (front == rear) cout << front->data << endl;
            else cout << front->data << ", " << rear->data;
        }
        void push(int val){
            size++;
            node* temp;
            temp->data = val;
            //
        }
        void pop(){}
};

int main(){
    return 0;
}