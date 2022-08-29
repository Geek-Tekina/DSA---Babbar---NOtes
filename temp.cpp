#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalin(char *string, int start, int end) {
    if (start >= end) return true;
    if (string[start] != string[end]) return false;
    return isPalin(string, start+1, end-1);
}

int countPalindrome(char *input1, int input2) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        //!
    } 
    return count;
}

int main(){
    char *s = "level";
    cout << isPalin(s, 0, 4) ;
}