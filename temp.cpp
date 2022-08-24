#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool isValid(vvi& temp,int n,int m,int i,int j){
    if(i>=0 && j>=0 && i<n && j<m && temp[i][j]==1){
        return true;
    }
    return false;
}

void dfs(vvi& temp,int n,int m,int i,int j,int &cnt){
    
    temp[i][j]=0;
    cnt++;
    
    if(isValid(temp,n,m,i-1,j)){
        dfs(temp,n,m,i-1,j,cnt);
    }
    
    if(isValid(temp,n,m,i,j+1)){
        dfs(temp,n,m,i,j+1,cnt);
    }
    
    if(isValid(temp,n,m,i+1,j)){
        dfs(temp,n,m,i+1,j,cnt);
    }
    
    if(isValid(temp,n,m,i,j-1)){
        dfs(temp,n,m,i,j-1,cnt);
    }
}



int main(){
    int n=3;
    int m=3;
    string temp;
    vvi grid(n, vi(m, 0));
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<m; j++){
            grid[i][j] = temp[j] == '1';
        }        
    }

    // process
    vector<int>ans;
    
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                dfs(grid,n,m,i,j,cnt);
                ans.push_back(cnt);
                cnt=0;
            }
        }
    }

    sort(ans.begin(),ans.end(), greater<int>());
    bool sureshTurn = false;
    int result = 0;
    for(auto it: ans){
        result += sureshTurn ? it : 0;
        sureshTurn = !sureshTurn;
    }

    // waste
    int total = 0;
    for(int i=0;i<ans.size();i++){
        total += ans[i];
        cout << ans[i] << " ";
    }
    cout << endl << "suresh : " << result << endl;
    cout << "mahes : " << total - result << endl;
    cout << "total : " << total << endl;

    return 0;
}