'''
You are given a string s consisting of lowercase letters and an integer k. We call a string t ideal if the following conditions are satisfied:

t is a subsequence of the string s.
The absolute difference in the alphabet order of every two adjacent letters in t is less than or equal to k.
Return the length of the longest ideal string.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

Note that the alphabet order is not cyclic. For example, the absolute difference in the alphabet order of 'a' and 'z' is 25, not 1.
'''

# The other way of understanding this problem is Longest subsequence of a list whose adj elements diff is k

'''
def longSubseq(s: str, k: int) -> int:
    x = [ord(i)-97 for i in s]
    res = [1]*26

    for i in range(len(x)):
        for j in range(0, i):
            if abs(x[i] - x[j]) <= k: 
                res[i] = max(res[i], res[j]+1)
    return max(res)

Con: TLE error
'''


def longestIdealString(s: str, k: int) -> int:
    x = [ord(i)-97 for i in s]
    res = [0]*26

    for i in x:
        curr = 0
        for j in range(26):
            if abs(i-j) <= k:
                curr = max(curr, res[j] + 1)
        
        res[i] = max(res[i], curr)
    
    return max(res)
