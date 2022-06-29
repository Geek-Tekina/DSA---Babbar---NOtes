#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int coin_change1(vector<int> &coins, int amount){
    int t[coins.size()+1][amount+1];

    for(int i=0 ; i<=coins.size(); ++i)
        for(int left = 0 ; left<=amount ; ++left){
            if(left == 0)   t[i][left] = 0;
            else if(i == 0) t[i][left] = INT_MAX - 1;
            else if(coins[i-1] <= left){
                t[i][left] = min(t[i-1][left], t[i][left - coins[i-1]] + 1);
            } else {
                t[i][left] = t[i-1][left];
            }
        }
        // print 2d matrix
        for(int i=0 ; i<=coins.size(); ++i){
            for(int left = 0 ; left<=amount ; ++left){
                cout << t[i][left] << " ";
            }
            cout << endl;
        }
    return t[coins.size()][amount];
}

int coin_change2(vector<int> &coins, int amount){
    int t[coins.size()+1][amount+1];

    for(int i=0 ; i<=coins.size(); ++i)
        for(int left = 0 ; left<=amount ; ++left){
            if(left == 0)   t[i][left] = 1;
            else if(i == 0) t[i][left] = 0;
            else if(coins[i-1] <= left){
                t[i][left] = t[i-1][left] + t[i][left - coins[i-1]];
            } else {
                t[i][left] = t[i-1][left];
            }
        }
    return t[coins.size()][amount];
}

int main(){
    vector<int> coins = {1,2,5};
    cout << coin_change1(coins, 11);
    return 0;
}