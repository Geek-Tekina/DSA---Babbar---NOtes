#include <iostream>
#include <string>
using namespace std;

string removeConsecutiveDuplicates(string str) {
    string res="";
    for(int i=0 ; i<str.size() ;){
        char temp = str[i];
        res += temp;
        ++i;
        while( i<str.size() && str[i] == temp)  ++i;
    }
    return res;
}

int main(){
    cout << removeConsecutiveDuplicates("xxxyyyzwwz");
    return 0;
}