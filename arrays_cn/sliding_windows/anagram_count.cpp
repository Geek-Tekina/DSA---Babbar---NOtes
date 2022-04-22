#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
typedef string str;

int countAnagram(str s, str p){
    int res=0;
    unordered_map<char, int> mp;
    for(int i=0 ; i<p.size() ; ++i)
        ++mp[p[i]];
    
    int count = mp.size();

    // initial loop
    for(int i=0 ; i<p.size() ; ++i){
        if(mp.find(s[i])!=mp.end()){
            --mp[s[i]];
            if(mp[s[i]]==0)     --count;
        }
    }

    for(int i=p.size() ; i<s.size() ; ++i){
        // calculation
        if(count == 0){  
            cout << i-p.size();
            ++res;
        }

        // sliding window
        if(mp.find(s[i-p.size()])!=mp.end()){
            ++mp[s[i-p.size()]];
            if(mp[s[i-p.size()]] == 1)  ++count;
        }
        if(mp.find(s[i])!=mp.end()){
            --mp[s[i]];
            if(mp[s[i]] == 0)  --count;
        }
    }

    if(count == 0){  
        cout << s.size()-p.size();
        ++res;
    }
    return res;
}

int main(){
    cout << countAnagram("foxrofroofrro", "forr");
    return 0;
}