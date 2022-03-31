#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

vi rowWaveForm(vector<vi> &mat) {
    vi res;
    for(int i=0 ; i<mat.size() ; ++i){
        if(i & 1)
            for(int j = mat[0].size()-1 ; j>=0 ; --j)  res.push_back(mat[i][j]);
        else
            res.insert(res.end(), mat[i].begin(), mat[i].end());
    }
    return res;
}


int main(){
    vector<vi> arr = {{5,1,2}, {7,0,1} };
    vi res = rowWaveForm(arr);
    for(int i=0 ; i<res.size() ; ++i){
        cout << res[i] << " ";
    }
    return 0;
}