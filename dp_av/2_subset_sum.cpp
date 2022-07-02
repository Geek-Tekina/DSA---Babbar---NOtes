#include <iostream>
#include <vector>
using namespace std;

int items[] = {2,3,7,8,10};
int s = 5;
int sum=10;

bool solve(int n,int left){
    if(left == 0)   return true;
    if(n == 0)      return false;

    if(items[n-1] <= left){
        return ( solve(n-1, left-items[n-1]) || solve(n-1, left) );
    } else {
        return solve(n-1, left);
    }
}

bool dp(){
    bool **t;
    t = new bool*[s+1];
    for(int i=0 ; i<=s ; ++i)
        t[i] = new bool[sum+1];
    
    for(int i=0 ; i<=s ; ++i)
        for(int left = 0 ; left<=sum ; ++left){
            if(left == 0)   t[i][left] = true;
            else if(i == 0) t[i][left] = false;
            else if(items[i-1] <= left){
                t[i][left] = t[i-1][left - items[i-1]] || t[i-1][left];
            } else {
                t[i][left] = t[i-1][left];
            }
        }
    
    return t[s][sum];
}

int dp_count(){
    int **t;
    t = new int*[s+1];
    for(int i=0 ; i<=s ; ++i)
        t[i] = new int[sum+1];
    
    for(int i=0 ; i<=s ; ++i)
        for(int left = 0 ; left<=sum ; ++left){
            if(left == 0)   t[i][left] = 1;
            else if(i == 0) t[i][left] = 0;
            else if(items[i-1] <= left){
                t[i][left] = t[i-1][left - items[i-1]] + t[i-1][left];
            } else {
                t[i][left] = t[i-1][left];
            }
        }
    
    return t[s][sum];
}

int main(){
    // cout << solve(s, sum);
    cout << dp_count() << endl;
    return 0;
}