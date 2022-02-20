#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    // int A[] = {1,5,10,20,40,80};
    // int B[] = {6,7,20,80,100};
    // int C[] = {3,4,15,20,30,70,80,100};
    int A[] = {1,1,1};
    int B[] = {1,1,1};
    int C[] = {1,1,1};
    int n1 = sizeof(A)/sizeof(int);
    int n2 = sizeof(B)/sizeof(int);
    int n3 = sizeof(C)/sizeof(int);
    vector<int> res;    
    int i=0,j=0,k=0;
    while(i < n1 && j < n2 && k < n3){
        if((A[i] == B[j]) && (B[j] == C[k])){
            if(find(res.begin(), res.end(), A[i]) == res.end()) {                
                res.push_back(A[i]);
            } 
            i++; j++; k++;
        } else {
            int mi = min(A[i], B[j]);
            mi = min(mi, C[k]);
            if(mi == A[i])  i++;
            else if (mi == B[j])    j++;
            else    k++;
        }
    }
    for(int i=0 ; i<res.size();i++){
        cout << res[i] << endl;
    }
    return 0;
}