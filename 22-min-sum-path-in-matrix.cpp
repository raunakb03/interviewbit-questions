#include <bits/stdc++.h>
using namespace std;

// memoization
int f(vector<vector<int>> &grid, int i, int j, int n, int m,
      vector<vector<int>> &dp) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return 1e9;
  if (i == n - 1 && j == m - 1)
    return grid[i][j];
  if (dp[i][j] != -1)
    return dp[i][j];

  int down, right;
  down = f(grid, i + 1, j, n, m, dp);
  right = f(grid, i, j + 1, n, m, dp);

  return dp[i][j] = min(down, right) + grid[i][j];
}

// tabulation
int minPathSum(vector<vector<int>> &A) {
  int n = A.size(), m = A[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for(int i=1; i<n; i++){
      for(int j=0; j<m; j++){
          if(i==0 && j==0) {
              dp[i][j]= A[i][j];
              continue;
          }
          int up=1e9, left= 1e9;
          if(i-1>=0) up= dp[i-1][j];
          if(j-1>=0) left= dp[i][j-1];
          dp[i][j]= min(up, left)+A[i][j];
      }
  }
  return dp[n][m];
}
