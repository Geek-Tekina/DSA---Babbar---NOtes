#include <iostream>
#include <vector>
using namespace std;

class queue{
    // front pop, rear add
    vector<int> v;
    int front,rear;
    int size;
    public:
        queue(){
            v = {};
            size = 0;
            front = rear = -1;
        }
        int getSize(){  return size; };
        void getFR(){
            if(size == 0) cout << -1;
            else if(size == 1)    cout << v[front] << endl;
            else cout << v[front] << ", " << v[rear] << endl;
        }
        void push(int val){
            size++;
            if(front == -1) front++;
            rear++;
            v.push_back(val);
        }
        void pop(){
            if(front == rear || front == -1) {
                v={};
                front = rear = -1;
            }
            else {
                size--;
                v[front] = '\0';
                front++;
            }
        }
        void print(){
            for(int i=front ; i<=rear ; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }
};

int main(){
    queue q = queue();
    // q.push(10);
    q.getFR();
    q.push(20);
    q.push(30);
    cout << q.getSize() << endl;
    q.getFR();
    q.pop();
    q.getFR();
    q.print();
    return 0;
}