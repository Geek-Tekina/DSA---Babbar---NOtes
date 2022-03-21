#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

class stack {
    vector<int> v;
    int size;
    public:
        stack(){
            v = {};
            size = 0;
        }
        int getSize(){ return size; } 
        void push(int val){
            v.push_back(val);
            size++;
        }
        void pop(){
            v.pop_back();
            size--;
        }
        int top(){
            return v[size-1];
        }
        void print(){
            for(int i=size-1 ; i>=0 ; i--){
                cout << v[i] << " ";
            }
            cout << "\n";
        }
};

int main(){
    // stack<int> s;
    // s.push(10);
    // s.push(20);
    // s.pop();
    // while (!s.empty()) {
    //     cout << ' ' << s.top();
    //     s.pop();
    // }
    stack s = stack();
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.getSize() << endl;
    cout << s.top() << endl;
    s.pop();
    s.print();
    return 0;
}