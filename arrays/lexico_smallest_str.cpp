#include <iostream>
#include <vector>
using namespace std;

vector<char> parent(26);
char findParent(char x){
    if(parent[x-'a'] == x)
        return x;
    return parent[x-'a'] = findParent(parent[x-'a']);
}

string smallestEquivalentString(string s1, string s2, string baseStr) {
    for(char i='a' ; i<='z' ; ++i)
        parent[i-'a'] = i;
    
    for(int i=0 ; i<s1.size() ; ++i){
        char p1 = findParent(s1[i]);
        char p2 = findParent(s2[i]);
        if(p1 < p2)
            parent[p2-'a'] = p1;
        else
            parent[p1-'a'] = p2;
    }

    for(int i=0 ; i<baseStr.size() ; ++i)
        baseStr[i] = findParent(baseStr[i]);
    return baseStr;
}

int main(){
    cout << smallestEquivalentString("hello", "world", "hold");
    return 0;
}