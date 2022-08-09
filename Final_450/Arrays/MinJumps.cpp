#include <bits/stdc++.h>
using namespace std;

// True or false
bool canJump(vector<int> nums)
{
    int n = nums.size();

    int maxReach = nums[0] + 0, lastIdx = n - 1;

    for (int i = 0; i <= maxReach and maxReach <= lastIdx; i++)
    {
        maxReach = max(nums[i] + i, maxReach);
    }
    return maxReach >= lastIdx;
}

int minJumps(vector<int> nums)
{int n = nums.size();
    int cnt = 0, i = 0;
    if(n <= 1) return 0;
        
    while (i < n)
    {
        int steps = nums[i];
        int maxReach = nums[i] + i;
        int maxReachIdx = i;
        if(steps == 0) return -1;
        for (int j = i+1; j < i + steps + 1; j++)
        {
            if(j == n-1) return cnt+1;
            if (maxReach <= nums[j] + j)
            {
                maxReach = nums[j] + j;
                maxReachIdx = j;
            }
        }
        i = maxReachIdx;
        cnt++;
    }
        
    return cnt;
}