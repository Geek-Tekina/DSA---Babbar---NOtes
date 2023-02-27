#include <bits/stdc++.h>
#include <queue>
using namespace std;
void operate(auto &pq);

/* for heap, we write 
priority_queue<...> - push(), top(), pop(), empty()
    data-type
    vector<data-type> : because pq is nothing but a vector and not a tree
    comparator : can be greater<data-type>(small one first)
                or, structure compare with operator overloading()

Min Heap : smallest value at top
Max Heap : largest value at top
*/

struct compareMin{
    bool operator()(int a, int b){
        return a>b;
    }
};

int main(){
    // default: max heap
    priority_queue<int> maxheap1;
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> minheap1;
    priority_queue<int, vector<int>, compareMin> minheap2;
    
    operate(minheap1);
    return 0;
}

void operate(auto &pq){
    cout << "adding 1,2,3 and priting top() : ";
    pq.push(1);
    pq.push(2);
    pq.push(3);
    cout << pq.top();
    cout << "\n";
}