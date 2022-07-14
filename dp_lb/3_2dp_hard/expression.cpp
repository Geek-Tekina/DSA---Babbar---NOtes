#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <stack>
using namespace std;
typedef unordered_set<int> usi;

int eval(int a, char op, int b){
    if(op == '+')   return (a + b);
    else        return (a * b);
}

// MCM based
usi solve(int i, int j, string s){
    if(i == j)  return {s[i] - '0'};
    if(i > j)  return {};

    usi answers;
    for(int k=i; k<=j ;){
        usi c1 =  solve(i, k-2, s);
        usi c2 =  solve(k+2, j, s);
        if(c1.size() != 0){
            for(int a: c1){
                a = eval(a, s[k-1], s[k] - '0');
                if(c2.size() != 0){
                    for(int b: c2){
                        answers.insert(eval(a, s[k+1], b));
                    }
                }
            }
        } else {
            if(c2.size() != 0){
                for(int b: c2){
                    answers.insert(eval(s[k] - '0', s[k+1], b));
                }
            }
        }
        
        k+=2;
    }    
    return answers;
}

int correctAns(string& s) {
    stack<int> stk;
    for (int i = 0; i < s.size(); ++i) {
        if (stk.empty()) {
            stk.push(s[i] - '0');
        } else {
            if (s[i] == '+') {
                stk.push(-1);
            } else if (s[i] == '*') {
                stk.push(-2);
            } else {
                int value = (s[i] - '0');
                while (!stk.empty() && stk.top() == -2) {
                    stk.pop();
                    value *= stk.top();
                    stk.pop();
                }
                stk.push(value);
            }
        }
    }
    int ans = 0;
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
        if (!stk.empty()) {
            stk.pop();
        }
    }
    return ans;
}

int main(){
    string s = "1+2*3+4";
    usi all_answers = solve(0, s.size()-1, s);
    for(auto it : all_answers){
        cout << it << endl;
    }
    cout << "===\n";
    cout << correctAns(s) << endl;
    return 0;
}