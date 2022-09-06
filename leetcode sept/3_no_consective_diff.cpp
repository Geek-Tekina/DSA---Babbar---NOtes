#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vector<int> numsSameConsecDiff(int n, int k) {
    vvi mp(10);
    for (int i = 9; i >= 0; --i) {
        if( i+k <= 9 ) mp[i].push_back(i+k);
        if( i-k >= 0 ) mp[i].push_back(i-k);
    }
    // print mp
    for (int i = 0; i < mp.size(); ++i) {
        cout << i << ": ";
        for (int j = 0; j < mp[i].size(); ++j) {
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> res  = {};  
    for(int i=1 ; i<=9 ; i++) {
        for(int j=0 ; j<mp[i].size() ; j++) {
            int num = i;
            int lastDigit = mp[i][j];
            int temp = n;
            while(--temp){
                num = num*10 + lastDigit;
                lastDigit = mp[lastDigit];
            }
            res.push_back(num);
        }
    }
    return res;
}


void f(long long num,int n,int k,vector<int> &ans){
    if(n==0) {ans.push_back(num);return;}
    int lower=((num==0)?1:0);
    for(int i=lower;i<10;i++){
        if(num and abs(i-num%10)!=k) continue;
        num*=10;num+=i;
        f(num,n-1,k,ans);
        num/=10;
    }
}
    
vector<int> numsSameConsecDiff2(int n, int k) {
    vector<int> ans;
    long long num=0;
    f(num,n,k,ans);
    return ans;
}


int main(){
    vector<int> res = numsSameConsecDiff(3, 2);
    for(auto it : res){
        cout << it << " ";
    }
    return 0;
}