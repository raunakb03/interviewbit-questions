#include<bits/stdc++.h>
using namespace std;

// number of distinct ways to make subsequence b form subsequence a
// dp[i][j] number of ways to make b till length j from the string a till length i
int numDistinct(string A, string B) {
    int n= A.size();
    int m= B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0]= 1;
    for(int i=0; i<=m; i++) dp[0][i]= 0;
    dp[0][0]= 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]= dp[i-1][j-1];
            } 
            dp[i][j]= dp[i-1][j];
        }
    }
    return dp[n][m];
}
