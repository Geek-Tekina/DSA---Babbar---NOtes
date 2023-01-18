#include <iostream>
#include <vector>
using namespace std;

/*
Q. given a list of gas and cost[i], it takes cost to go from i to i+1, 
and you get gas[i] at ith station.
Find starting stn such that you can make the round trip, if not then -1

 
Approach 1: Bruteforce
for every station, extra_fuel = 0
    traverse every other stn - i to n 
    then traverse every other stn - 0 to i
    in this do extra_fuel += gas[i] - cost[i]
    if extra_fuel < 0, then check another station
    else return i

Approach 2: Greedy
the concept is if we start from S1 and get a negative extra_fuel value at S3
then logically S1, S2 and S3 are not good starting points
so we will try to use S4 as new answer and by this moment 
we also know that we need ef to reach S4 from S1, 
so we will store it in req_fuel
hence, 
if(ef < 0){
    start = i+1;
    rf += ef;
    ef = 0;
}

at the end if ef + rf >= 0, then return it was a valid point else return -1
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0;
    int ef = 0;
    int rf = 0;
    for(int i=0 ; i<gas.size() ; ++i){
        ef += gas[i] - cost[i];
        if(ef < 0){
            start = i+1;
            rf += ef;
            ef = 0;
        }
    }
    return (ef + rf >= 0) ? start : -1; 
}

int main(){
    return 0;
}