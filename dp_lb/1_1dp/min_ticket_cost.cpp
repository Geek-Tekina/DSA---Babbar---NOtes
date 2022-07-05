#include <iostream>
#include <vector>
using namespace std;

vector<int> costs = {2,7,15};
vector<int> days = {1,4,6,7,8,20};
int solve(int n){
    if(n <= 0)  return 0;
    
    int oneDay = costs[0] + solve(n-1);

    int i;
    for(i=n-1 ; i>0 ; --i)
        if(days[n-1] - days[i-1] >= 7)
            break;
    int oneWeek = costs[1] + solve(i);

    for(i=n-1 ; i>0 ; --i)
        if(days[n-1] - days[i-1] >= 30)
            break;

    int oneMonth = costs[2] + solve(i);
    return min(oneDay, min(oneWeek, oneMonth));
}

int dp(){
    int n = days.size();
    int t[n+1];

    t[0] = 1;
    for(int i=1; i<=n; ++i){
        int day = costs[0] + t[i-1];

        int w;
        for(w=i-1 ; w>0 ; --w)
            if(days[i-1] - days[w-1] >= 7)
                break;
        int week = costs[1] + t[w];

        int m;
        for(m=i-1 ; m>0 ; --w)
            if(days[i-1] - days[m-1] >= 30)
                break;
        int month = costs[1] + t[m];
        t[i] = min(day, min(week, month));
    }
    return t[n];
}

int main(){
    cout << solve(days.size()) << endl;
    cout << dp() << endl;

    return 0;
}