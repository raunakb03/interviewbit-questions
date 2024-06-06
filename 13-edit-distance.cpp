#include<bits/stdc++.h>
using namespace std;

// min number of steps required to convert A to B
// dp[i][j] -> min number of steps required to convert A till length i to b till length j 
int minDistance(string A, string B) {
    int n1= A.size();
    int n2= B.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    for(int i=0; i<=n1; i++){
        dp[i][0]= i;
    }
    for(int i=0; i<=n2; i++){
        dp[0][i]= i;
    }
    for(int i=1; i<=n1; i++){
        for(int j=1; j<=n2; j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]= dp[i-1][j-1];
            } else {
                dp[i][j]= min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
            }
        }
    }
    return dp[n1][n2];
}
