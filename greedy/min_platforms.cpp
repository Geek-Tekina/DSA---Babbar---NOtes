#include <iostream>
#include <vector>
using namespace std;

/*
Q. Given arrival and departure times of all trains that reach a railway station. 
Find the min no of platforms so that no train is kept waiting.

Approach 1 : 
create a class and fit the arrival and departure times in the class.
sort the class based on the arrival time.
typedef vector<train> platform;
vector<platform> pList;
now this pList.size() will give the no of platforms required.
for each train, check pList[j].last train
    if valid then push back, else create new list in pList
TC - O(n*n)

Approach 2 :
same but instead of whole `platform` as list just store last boarded train
and instead of vector use priority_queue<arrTime, depTime>
TC - O(nlog(n))

Approach 3 : No Extra Space Approach
sort the arrival and departure times seperately 
iterate over the sorted array
for each arrival time, check if there is a departure time greater than it
if yes then we do need a platform hence platform++
else just move ++j
*/

int findPlatform(int arr[], int dep[], int n){
    sort(arr, arr+n);
    sort(dep, dep+n);
    
    int i=1, j=0, ans=1;
    while(i<n){
        if(arr[i]<=dep[j])
            ++ans;
        else ++j;
        ++i;
    }
    return ans;
}

int main(){
    return 0;
}