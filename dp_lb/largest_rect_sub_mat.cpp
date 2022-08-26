/*
To find the largest rectangle sub matrix where
    1. sum is maximum
    2. sum is 0
    3. Number of 0s and 1s are same
*/ 

/*
All these three questions of DP are based on the same concept.
Naive Approach : 
Run a loop for each starting row and then nested loop for ending row
Then nested starting column and then nested ending column
T(n) = O(n^4)

Efficient Approach :
Run a loop for each starting row and then nested loop for ending row
but create a vector presum which stores the sum of all the elements row-wise
such that presum[col] = sum of all elements from [r1][col] to [r2][col]
This can be done using another nested loop from 0 to C

for r1 = 0 to R
    vector<int> presum(C, 0);
    for r2 = r1 to R
        for col = 0 to C
            presum[col] += matrix[r2][col];
        // now here apply kadane's algorithm to find the maximum subarray
        // or apply prefixSum-Map concept to find largest subarray with sum as 0
        // for question three, convert 0s to -1 and then use 2nd question.

*/

#include <iostream>
#include <vector>
using namespace std;

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int ans=INT_MIN;
    for(int r1=0 ; r1<R ; ++r1){
        vector<int> preSum(C, 0);
        for(int r2=r1 ; r2<R ; ++r2){
            for(int c=0; c<C ; ++c){
                preSum[c] += M[r2][c];
            }
            // apply kadane's here
            int max_ending_here = 0, max_so_far = INT_MIN;
            for (int i = 0; i < C; i++) {
                if (preSum[i] <= max_ending_here + preSum[i]) 
                    max_ending_here += preSum[i];
                else    max_ending_here = preSum[i];
                if (max_ending_here > max_so_far)
                    max_so_far = max_ending_here;
            }
            ans = max(ans, max_so_far);
        }
    }
    return ans;
}

/*
PrefixSum - Map Approach :
for each element in the array, add it to a variable sum
if sum is in the map, it means this sum is already seen and from that index
to this index the sum of the subarray has been 0.
    max_i = max(max_i, i - prefixSum[sum])
else if sum is not in the map, then add it to the map

*/

*/

int main(){
    return 0;
}