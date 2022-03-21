#include <iostream>
#include <vector>
using namespace std;

class stack{
    vector<int> v;
    int size;
    vector<int> des;
    public:
        stack(){
            v = des = {};
            size = 0;
        }
        int getSize(){  return size; }
        void push(int data){
            size++;
            v.push_back(data);
            if(des.size() == 0)   des.push_back(data);
            else {
                if(des[des.size()-1] >= data)   des.push_back(data);
            }
        }
        int pop(){
            if(size == 0)   return -1;
            int temp = v[size-1];
            size--;
            v.pop_back();
            if(des[des.size()-1] == temp)   des.pop_back();
            return temp;
        }
        int top(){
            if(size == 0)   return -1;
            return v[size-1];
        }
        bool isEmpty(){ return (size == 0); }
        int getMin(){
            if(size == 0)   return -1;
            return des[des.size()-1];
        }
};

int main(){
    stack s = stack();
    s.push(2);
    s.push(0);
    s.push(1);
    s.push(5);
    s.push(-1);
    cout << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;
    cout << s.getMin() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.getMin() << endl;
    return 0;
}