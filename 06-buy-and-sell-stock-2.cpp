#include <bits/stdc++.h>
using namespace std;

/*dp[i][0] -> max profit till index i such that i have no stock bought*/
/*dp[i][1] -> max profit till index i such that i have stock bought on index i*/
int maxProfit(const vector<int> &A) {
  int n = A.size();
  vector<vector<int>> dp(n + 1, vector<int>(2, -1e9));
  dp[n][0]=0;
  dp[n][1]=0;
  for(int i=n-1; i>=0; i--){
      for(int buy=0; buy<=1; buy++){
          if(buy){
              dp[i][buy]= max(-A[i]+dp[i+1][0],  dp[i+1][1]);
          } else {
              dp[i][buy]= max(A[i]+dp[i+1][1], dp[i+1][0]);
          }
      }
  }
 return dp[0][1];
}
