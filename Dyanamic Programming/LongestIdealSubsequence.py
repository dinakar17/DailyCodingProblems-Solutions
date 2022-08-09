# https://leetcode.com/contest/weekly-contest-305/problems/longest-ideal-subsequence/

class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        res = [0]*26
        x = [ord(i)-97 for i in s]
        
        for i in x:
            curr = 0
            for j in range(26):
                if(abs(i-j) <= k):
                    curr = max(curr, res[j]+1)
            # curr += 1
            res[i] = max(curr, res[i])
        
        return max(res)