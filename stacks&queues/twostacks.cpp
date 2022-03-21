#include <iostream>
#include <vector>
using namespace std;

class twostack{
    int *arr;
    int size,t1,t2;
    public:
        twostack(int s){
            arr = new int[size];
            size = s;
            t1 = -1;
            t2 = s;
        }
        void push1(int val){
            if(t1+1 == t2)  return;
            t1++;
            arr[t1] = val;
        }
        void push2(int val){
            if(t1+1 == t2)  return;
            t2--;
            arr[t2] = val;
        }
        int pop1(){
            if(t1 == -1) return -1;
            t1--;
            return arr[t1+1];
        }
        int pop2(){
            if(t2 == size)  return -1;
            t2++;
            return arr[t2-1];
        }
};


int main(){
    twostack s = twostack(10);
    s.push1(10);
    s.push1(11);
    s.push1(12);
    s.push2(20);
    s.push2(21);
    cout << s.pop1() << s.pop2();
    return 0;
}