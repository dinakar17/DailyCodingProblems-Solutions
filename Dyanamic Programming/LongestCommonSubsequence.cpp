#include<bits/stdc++.h>
using namespace std;


int longestCommonSubSeq(string a, string b, int i, int j){
    // if the strings are empty, then there is no subsequence in common
    if(i == 0 || j == 0) return 0;
    // i = n-1 and j = m-1
    if(a[i-1] == b[j-1]){
        return (1 + longestCommonSubSeq(a, b, i-1, j-1));
    }
    return max(longestCommonSubSeq(a, b, i-1, j), longestCommonSubSeq(a, b, i, j-1));
}

int longestCommonSeq(string a, string b){
    int m = a.size();
    int n = b.size();

    int dp[m+1][n+1];

    // base cases
    for(int i = 0; i < n; i++) dp[0][i] = 0;
    for(int i = 0; i < m; i++) dp[i][0] = 0;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];

}

int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout << longestCommonSeq(a, b);
}