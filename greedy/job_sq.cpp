#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Q. Given list of profits and deadline, each job takes one day. find max profit
Note - if a job has deadline 2, then it can be done on either day 1 or 2.

Approach :
Sort on the basis of profit because thats important for us
for each job
    we want to check if we can do this job on its deadline day,
    if not can we do one day before and so on...
    for this use a vector of bool to keep track of the days we can do the job
    we dont want to care about profit bec its maximised due to sorting
    so for any job, check from i to 0, if day_taken is false then only update the profit 
*/

struct Job {
    int id;
    int dead;
    int profit;
};

bool compare(Job &j1, Job &j2){
    return j1.profit > j2.profit;
}

int main(){
    Job arr[] = {{ 1, 2, 100 },
                 { 2, 1, 19 },
                 { 3, 2, 27 },
                 { 4, 1, 25 },
                 { 5, 3, 15 } };
   
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<n; i++){
        cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << endl;
    }
    cout << endl;


    sort(arr, arr+n, compare);
    vector<bool> flag(n, false);
    int maxProfit = 0;
    for(int i=0 ; i<n ; ++i){
        for(int j = min(arr[i].dead, n)-1 ; j>=0 ; --j){
            if(!flag[j]){
                flag[j] = true;
                maxProfit += arr[i].profit;
                break;
            }
        }
    }
    cout << "Max Profit = " << maxProfit << endl;


    for(int i=0; i<n; i++){
        cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << endl;
    }
    return 0;
}