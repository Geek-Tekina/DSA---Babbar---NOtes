#include <iostream>
using namespace std;

int main(){
    int n=3,set=2;

    int high=0, sum=0;
    while(n--)  high = high*10 + 1;
    int highd = 0;
    int base = 1;
    while (high) {
        int lastDigit = high % 10;
        high /= 10;
        highd += lastDigit*base;
        base = base*2;
    }
    ++highd;
    while(highd--)
        if(__builtin_popcount(highd) == set)    
            sum+=highd;
    cout << sum;
}