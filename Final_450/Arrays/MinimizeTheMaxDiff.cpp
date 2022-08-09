#include<bits/stdc++.h>
using namespace std;


int MinimizeTheMaxHeights(vector<int> heights, int k){
    int n = heights.size();
    int min_val = heights[0];
    int max_val= heights[n-1];
    int ans = max_val - min_val;

    for(int i = 1; i < n; i++){
        min_val = min(heights[0] + k, heights[i] - k);
        max_val = max(heights[i-1] + k, heights[n-1] - k);

        ans = min(ans, max_val - min_val);
    }
    return ans;
}