#include<bits/stdc++.h>
using namespace std;


int EditDist(string a, string b, int m, int n){
    // base cases
    if(m == 0) return n;
    if(n == 0) return m;

    if(a[m-1] != b[n-1]){
        return 1 + min({EditDist(a, b, m-1, n), EditDist(a, b, m, n-1), EditDist(a, b, m-1, n-1)});
    }
    return EditDist(a, b, m-1, n-1);
}

int EditDistance(string a, string b){
    int m = a.size();
    int n = b.size();

    int dp[m+1][n+1];

    // base cases
    for(int i = 0; i <= n; i++) dp[0][i] = i;
    for(int j = 0; j <= m; j++) dp[j][0] = j;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(a[i-1] != b[j-1]) dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            else dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[m][n];
}


int main(){
    string a = "sunday";
    string b = "saturday";
    cout << EditDist(a, b, a.size(), b.size());
}