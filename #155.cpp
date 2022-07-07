/* 
This problem was asked by MongoDB.

Given a list of elements, find the majority element, which appears more than half the time (> floor(len(lst) / 2.0)).

You can assume that such element exists.

For example, given [1, 2, 1, 1, 3, 4, 0], return 1.
*/

#include<bits/stdc++.h>
using namespace std;
// Understand this through this example: [3, 2, 2, 4, 2, 2] => [011, 010, 010, 100, 010, 010]
// 3 - 0 1 1
// 2 - 0 1 0
// 2 - 0 1 0
// 4 - 1 0 0 
// 2 - 0 1 0
// 2 - 0 1 0
//-----------
// 2 - 0 1 0
int majorityElement(vector<int> nums){
    int n = nums.size();
    int ans = 0;
    for(int b = 0; b < 32; b++){
        int ones = 0;
        for(int i = 0; i < n; i++){
            // 1 << 0 => 2^0 , 1 << 1 => 2^1 , 1 << 2 => 2^2 
            // We're counting number of ones in every column(fig above). i.e., there is just 1 "one" in rightmost column,
            // 5 "one" in second column and just 1 "one" again in third column from the right
            if(1 << b & nums[i]) ones += 1;
        }
        // for rightmost column we just have one so ans = 0
        // for second column one's > n/2 => ans = 0 + 2 = 2
        // for third column from the right => ans = 2 + 0 = 2
        if(ones > n/2) ans += (1 << b);
    }

    return ans;

}