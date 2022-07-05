#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<char>> vvc;

// https://www.youtube.com/watch?v=RElcqtFYTm0
int dp(vvc& matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int t[rows+1][cols+1];

    int largest = 0;
    for(int i=0 ; i<=rows ; ++i)
        for(int j=0 ; j<=cols ; ++j){
            // 0 means no element and not-0th index element
            // hence if no element is there, no sq. will be possible
            if(i == 0 || j == 0)    t[i][j] = 0;

            else if(matrix[i-1][j-1] == '1'){
                // treating current cell matrix[i-1][j-1] as bottom-right corner of a sq.
                // hence top, left, diagnoal and right should be checked whats the max. sq they can form
                // the min of their value + 1 (current cell is 1 hence atleast it can make 1 sized sq.)
                t[i][j] = 1 + min(t[i-1][j], min(t[i][j-1], t[i-1][j-1]));
            } else t[i][j] = 0;
            largest = max(largest, t[i][j]);
        }
    return largest*largest;
}

int main(){
    vvc matrix =  { {'1', '0', '1', '0', '0'}, 
                    {'1', '0', '1', '1', '1'}, 
                    {'1', '1', '1', '1', '1'}, 
                    {'1', '0', '0', '1', '0'} };
    cout << dp(matrix);
    return 0;
}