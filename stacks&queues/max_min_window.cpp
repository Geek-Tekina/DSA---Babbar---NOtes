/*
the approach here is to pick a number and check till how far is it smaller
because as long as it is smaller than its neighbour IT IS A CANDIDATE.
e.g. you reach on to the minimum element of the array, you will find that is reach is almost the whole array
and hence we can put it on the result[n-1] index
and if any value has a reach of just 3 values (l+r combined), then put it on result[3], bec till now for window
size of 3 we can find that this is the maximum element we cant get ... if another element has the same reach then store the greater one

now for all the result indices that are still empty, observe that the result[i+1] value can be put as it is the greatest 
element found in the window size and no lesser element can now be find.
*/

/*
Approach : using nextSmaller and previourSmaller methods
    firstly initialise l[n], r[n] two arrays -1
    find prevSmall and nextSmall in these arrays respectively 
    initialise result[n+1] with 0 value
    To run a loop for all elements and calculate reach 
        such that the reach for i will be, len = r[i] - l[i] - 1 
        and result[len] = max(result[len], arr[i])
    and now if any result[i] is 0 then put the value of result[i+1],
    but make sure it traverse in --i manner

for explanation - https://youtu.be/CK8PIAF-m2E
*/
