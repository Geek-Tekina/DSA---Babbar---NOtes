#include <iostream>
#include <vector>
#include<climits>
using namespace std;
typdef vector<int> vi;
typdef vector<vector<int>> vvi;

int gn,gm;
void dfs(int **mat,vector<vector<int>> &vis,int row,int col, int x,int y,int &res,int cost){
    if (row < 0 || row >= gn || col < 0 || col >= gm || vis[row][col] == 1  || mat[row][col] == 0)
        return;
    if(row == x and col == y){
        if(cost < res)  res = cost;
        return;
    }
    vis[row][col] = 1;
    dfs(mat,vis,row,col-1,x,y,res,cost);
    dfs(mat,vis,row,col+1,x,y,res,cost);
    dfs(mat,vis,row+1,col,x,y,res,cost+1);
    dfs(mat,vis,row-1,col,x,y,res,cost+1);
    // vis[row][col] = 0;
}

int minCostToDestination(int **matrix, int n, int m, int x, int y){
    int res = INT_MAX;
    vector<vector<int>> vis(n,vector<int>(m,0));
    gn = n;
    gm = m;
    dfs(matrix,vis,0,0,x,y,res,0);
    if(res == INT_MAX)
        return -1;
    return res;
}

int main(){
    vector<vector<int>> matrix =   {{1, 0, 1, 0, 0},
                                    {1, 0, 1, 1, 1},
                                    {1, 1, 1, 0, 1},
                                    {0, 0, 0, 0, 1},
                                    {1, 1, 1, 1, 1}};
    cout << minCostDest(matrix, 3, 4) << endl;
    return 0;
}