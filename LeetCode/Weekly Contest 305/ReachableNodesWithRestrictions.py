'''
Link: https://leetcode.com/contest/weekly-contest-305/problems/reachable-nodes-with-restrictions/
Description:
There is an undirected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree. You are also given an integer array restricted which represents restricted nodes.

Return the maximum number of nodes you can reach from node 0 without visiting a restricted node.

Note that node 0 will not be a restricted node.
'''
from collections import defaultdict
from typing import List

def reachableNodes( n: int, e: List[List[int]], restricted: List[int]) -> int:
    edges = defaultdict(list) # dict with values as lists
    for i, j in e:
        edges[i].append(j)
        edges[j].append(i)
    
    seen = [False]*n
    ok = [True]*n

    for i in restricted:
        ok[i] = False # note that elements are restricted from 0 to n-1

    def dfs(x):
        seen[x] = True
        
        for i in edges[x]:
            if seen[i] == False and ok[i]:
                dfs(i)
    dfs(0)

    return sum(seen)



