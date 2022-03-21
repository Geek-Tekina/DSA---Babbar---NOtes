#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class data{
    public:
    int key, value;
    data(int k, int v){key = k; value = v;}
};

class LRUCache{
    int cap;
    queue<data> q;
    unordered_set<int> hash;

    public:
    LRUCache(int capacity){ cap = capacity; }
    int get(int key){
        if(hash.find(key) == hash.end()) { return -1; }

        queue<data> q2;
        data keyData = data(0,0);
        while(!q.empty()){
            if(q.front().key == key) { keyData = q.front(); } 
            else { q2.push(q2.front()); }
            q.pop();
        }
        q2.push(keyData);
        q = q2;
        return keyData.value;
    }

    void put(int key, int value){
        hash.insert(key);
        if(hash.find(key) == hash.end()){
            if(q.size() >= cap){
                data popdata = q.front();
                hash.erase(hash.find(popdata.key));
                q.pop();
            }
            q.push(data(key, value));
            cout << q.front().value << endl;
        } else {
            queue<data> q2;
            while(!q.empty()){
                if(q.front().key == key) { q.front().value = value; } 
                q2.push(q2.front());
                q.pop();
            }
            q = q2;
        }
    }
};

int main(){
    LRUCache l = LRUCache(3);
    l.put(1,1);
    l.put(2,2);
    l.put(3,3);
    l.put(4,5);
    cout << l.get(3) << l.get(1) << l.get(4);
    l.put(2,3);
    cout << l.get(1) << l.get(3) << l.get(2);
    return 0;
}