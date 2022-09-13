#include <iostream>
#include <string>
using namespace std;

int f(string i, char s){
    int idx=0;
    do {
        if(i[idx] == s){
            return idx;
        }
        ++idx;
    } while( i[idx]!=0);
    return -1;
}

int main(){
    cout << f("HELLO WORLD", 'L');
}