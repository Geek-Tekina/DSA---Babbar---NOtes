#include <iostream>
#include <vector>
using namespace std;

bool isSubSequence(string str1, string str2) {
    if(str1.size() > str2.size())
        return false;
    else if (str1.size() == str2.size())
        return (str1.compare(str2)) == 0;
    int i=0, j=0;
    for(; i<str1.size() && j<str2.size();){
        if(str1[i] == str2[j]){	++i; ++j; }
        else  ++j;
    }
    if(i!=str1.size())	return false;
    return true;
}

int main(){
    cout << isSubSequence("ape", "bape");
    return 0;
}