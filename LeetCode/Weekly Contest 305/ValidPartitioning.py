'''
You are given a 0-indexed integer array nums. You have to partition the array into one or more contiguous subarrays.

We call a partition of the array valid if each of the obtained subarrays satisfies one of the following conditions:

The subarray consists of exactly 2 equal elements. For example, the subarray [2,2] is good.
The subarray consists of exactly 3 equal elements. For example, the subarray [4,4,4] is good.
The subarray consists of exactly 3 consecutive increasing elements, that is, the difference between adjacent elements is 1. For example, the subarray [3,4,5] is good, but the subarray [1,3,5] is not.
Return true if the array has at least one valid partition. Otherwise, return false.

'''
# from functools import cache
from functools import cache
from typing import List

def validPartition( nums: List[int]) -> bool:
    n = len(nums)

    @cache
    def ans(x):
        if x == n:
            return True
        if x + 1 < n and nums[x] == nums[x+1] and ans(x+2):
            return True
        if x + 2 < n and nums[x] == nums[x+1] == nums[x+2] and ans(x+3):
            return True
        if x + 2 < n and nums[x] + 1 == nums[x+1] == nums[x+2] - 1 and ans(x+3):
            return True
        return False

    return ans(0)
