#include <iostream>
#include <vector>
using namespace std;

int items[] = {1,2,3};
int diff = 1;
int n = sizeof(items)/sizeof(items[0]);

int dp(int left){
    int t[n+1][left+1];

    for(int i=0 ; i<=n ; ++i)
        for(int j=0 ; j<=left ; ++j){
            if(j == 0)  t[i][j] = 1;
            else if (i == 0)    t[i][j] = 0;
            else if( items[i-1]<=j ){
                t[i][j] = t[i-1][j] + t[i-1][j - items[i-1]];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    // print 2d matrix
    for(int i=0 ; i<=n ; ++i){
        for(int j=0 ; j<=left ; ++j){
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
    return t[n][left];
}

int main(){
    int totalsum = 0;
    for(int i=0;i<n; ++i){
        totalsum += items[i];
    }    
    int sumOfSubset1 = (diff + totalsum)/2;
    cout << dp(sumOfSubset1) << endl;
    return 0;
}