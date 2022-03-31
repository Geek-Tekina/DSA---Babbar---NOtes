#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    int a[n];
    for(int i=0 ; i <n ; ++i)	cin >> a[i];
    cin >> k;
    int temp[k+1];
    
    for(int i=0 ; i<k ; ++i)	temp[i] = a[i];
    for(int i=k ; i<n ; ++i)	a[i-k] = a[i];
    for(int i=n-k ; i<n ; ++i)	a[i] = temp[i-n+k];
    for(int i=0 ; i<n ; ++i)	cout << a[i] << " ";

    return 0;
}