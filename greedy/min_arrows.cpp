#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int findMinArrowShots(vector<vector<int>>& points) {
    int n = points.size();
    if(n == 0) return 0;
    sort(points.begin(), points.end(), [](const vi& a, const vi& b){
        if(a[0] != b[0]) return a[0] < b[0];
        else return a[1] < b[1];
    });
    int count = 1;
    vi cur = points[0];
    for(int i=1 ; i<points.size() ; ++i){
        if(cur[1] >= points[i][0]){
            // overlapping, hence minimax and maximini
            cur[0] = points[i][0];
            cur[1] = min(cur[1], points[i][1]);
        } else {
            // no overlapping, hence new balloon
            count++;
            cur = points[i];
        }
    }
    return count;
}

int main(){
    vvi points = {{1,2}, {2,3}, {3,4}, {4,5}};
    // vvi points = {{10,16}, {2,8}, {1,6}, {7,12}};
    cout <<  findMinArrowShots(points) << endl;
    return 0;
}