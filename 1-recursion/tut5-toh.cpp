#include <iostream>
#include <vector>
using namespace std;

void toh(char s, char a, char d,int n){
    if(n==1){
        cout << "from " << s << "->" << d << endl;
        return;
    }
    toh(s,d,a,n-1);
    cout << s << "->" << d << endl;
    toh(a,s,d,n-1);
}

int main(){
    toh('A','B','C',3);
    return 0;
}