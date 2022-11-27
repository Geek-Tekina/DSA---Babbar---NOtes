#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
typedef vector<string> vs;
typedef vector<vs> vvs;

/*
subsq wouldve been done by lcs of string and rev string
or another dp method with 2d array that uses two pointer approach and dp table

substring is a bit similar if you think about is, its just instead of having vv of string
we can boolean vv, to check for subtring(i, j) is it a palindrome or not

how to proceed?
create a vvs/ vvb
for sq/trings of length 1 (single char => isPal)       hence dp[i][i+1] = s[i]/ true
for sq/strings of length 2 (if s[i] == s[i+1] => isPal) hence dp[i][i+1] = s[i] + s[i+1] / true

for substrings of length > 3
    for this we first get the ending index of substring from starting index i and length k 
    then we check for substr(i, j) if s[i+1] to s[j-1] is a palindrome
sub
*/

// subsequence
string longestPalindromicSubsequence(string s){
    int n = s.size();
    vector<vector<string>> dp(n, vs(n, ""));
    for(int i=0 ; i<n ; ++i)    dp[i][i] = s[i];
    for(int len=2 ; len<=n ; ++len){
        for(int i=0 ; i<n-len+1 ; ++i){
            int j = i+len-1;
            if(s[i] == s[j] && len == 2)    dp[i][j] = s.substr(i, 2);
            else if(s[i] == s[j])   dp[i][j] = s[i] + dp[i+1][j-1] + s[j];
            else    dp[i][j] = dp[i+1][j].size() > dp[i][j-1].size() ? dp[i+1][j] : dp[i][j-1];
        }
    }
    return dp[0][n-1];
}

int main(){
    cout << longestPalindromicSubsequence("babadb") << endl;
    cout << longestPalSubstring("babadb") << endl;
    return 0;
}