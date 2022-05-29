## Sliding window
- **for Reff** : [Youtube Playlist](https://www.youtube.com/watch?v=EHCGAZBbB88&list=PL_z_8CaSLPWeM8BDJmIYDaoQ5zuwyxnfj)
- write a bruteforch approach first
- now observe your repetitive work
- it is of two types
    - fixed size window
    - variable size window

### fixed size
- if u have to store only useful items then `deque` can be used, that too to store only indices so that you can pop when index goes out of `k`.
    - Example question - https://www.geeksforgeeks.org/first-negative-integer-every-window-size-k/ 
- comparatively `variable size window` is a bit tough and it requires `map, set, etc.`
- the whole code can be divided into three different functions - `initial loop`, `calculation` for answer, and `sliding` and **four steps**
```cpp
for(0 to k)        // initial loop
for(k to n){
    // calculation
    // now, slide window
}
// now again calculation
```

### variable sized
- in fixed size window we knew till when we have to run the initial loop
    - but in case of variable sized window, the initial loop till k is not possible and hence we dont use it here.
- and remember, while sliding the window, even more than one element can be removed.
- you have to maintain **two pointers** here
```cpp
for(j = 0 to n){
    if cond < k
        // extend the window
    if cond == k
        // ans = calculation    
    else if cond > k {
        while(cond > k)    
            // shrink window from i
            ++i
    }
} 
```

### Questions
- Maximum Sum Subarray of size k
    ```cpp
    int res = 0;
    int curr_sum = res;
    // initial loop
    for (int i=0; i<k; i++)    curr_sum += arr[i];

    for (int i=k; i<n; i++)    {
        res = max(res, curr_sum);            // calculation
        curr_sum += arr[i] - arr[i-k];       // sliding
    }
    res = max(res, curr_sum);                // again last calculation
    ```
- [First negative number in every window of size k](arrays_cn/sliding_windows/first_neg_of_k.cpp)
- [Find count of occurences of anagrams of a pattern in a string](arrays_cn/sliding_windows/anagram_count.cpp) ; use maps
    - Find count of a pattern in a string ; **KMP**

-  **not from sliding window**, Subarray Sum Equals K (prefix sum)
    ```cpp
    // the question solved by Aditya Verma is for only positive integers and
    // this soln is for all integers. 
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1; // Because getting zero sum is always possible.
        int sum = 0, ans = 0;
        for(int i = 0;i<nums.size();i++) {
            sum = sum + nums[i];
            // use the number of times the required sum has already occurred 
            int req =  sum - k;
            if(mp.find(req)!=mp.end())    ans+=mp[req];
            mp[sum]+=1;
        }
        return ans;
    }
    ```
---
- [Largest Substring with k unique characters](arrays_cn/sliding_windows/longest_substring_k_unique_chars.cpp)
- [Length of longest substring](arrays_cn/sliding_windows/len_longest_substring_wo_repeating.cpp) 
- Pick toys ; basically its largest substring with k unique characters taking k as 2
- [Maximum sum subarray](https://leetcode.com/problems/maximum-subarray) (**Kadane's Algo**)



## Kadane Algo
The idea of Kadane’s algorithm is to maintain a `maximum subarray sum` ending at every index `'i'` of the given array and update the maximum sum obtained by comparing it with the maximum sum of the subarray ending at every index `'i'`.
```cpp
// base code is 
int maxSubArray(vector<int>& a) {
    int max=INT_MIN, sum = 0;
    for(int i=0 ; i<a.size() ; ++i){
        sum += a[i];
        max = max > sum ? max : sum;
        if(sum < 0)	sum=0;
    }
    return max;
}
```

- [Flip bits](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381872) ; take 0 as +1 and 1 as -1, now find the max subarray sum (this will give you the largest zeroes subarray) and meanwhile also count the number of 1s present and just return ones + larget zero subarray
- [K concatenation](https://leetcode.com/problems/k-concatenation-maximum-sum/)
    - if your k is 1 then just use `kadane(arr)`
    - but if not then also do not care about k right now
    - now find sum of whole array, if the `sum is less than 0` then we know that we cannot simply add all the arrays.
    - in this case we can use `kadane(arr + arr)`
    - but if the sum is greater than 0, then ultimately adding all the concatedarrs in between and only **selected** elements from extreme end arrays will help. hence it will be `kadane(arr + arr)  + (k-2)*sum`
    - k-2 because we are not processing left and right concated arrays. 
    - https://www.youtube.com/watch?v=qnoOu5Usb4o
- [Max Rect area](https://www.youtube.com/watch?v=kKEX4P53MyY)