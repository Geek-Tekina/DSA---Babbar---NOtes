#include <iostream>
#include <climits>
using namespace std;

int **t;
int solve(int arr[], int i, int j){
    if(i>=j)    return 0;
    if(t[i][j] != -1)   return t[i][j];
    
    int mn = INT_MAX;
    for(int k=i ; k<=j-1 ; ++k){
        int temp = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
        mn = min(temp, mn);
    }   
    t[i][j] = mn;
    return mn;
}

int matrixMultiplication(int N, int arr[]){
    t = new int*[N];
    for(int i=0 ; i<N ; ++i)
        t[i] = new int[N];

    for(int i=0 ; i<N ; ++i)
        for(int j=0 ; j<N ; ++j)
            t[i][j] = -1;

    return solve(arr, 1, N-1);
}

int main(){
    int arr[] = {1, 2, 3, 4};
    cout << matrixMultiplication(sizeof(arr)/sizeof(arr[0]), arr) << endl;
    return 0;
}