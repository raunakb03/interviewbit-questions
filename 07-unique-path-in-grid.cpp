#include <bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &A) {

  int n = A.size();
  int m = A[0].size();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j])
        dp[i][j] = 0;
      else if (i == 0 && j == 0)
        dp[i][j] = 1;
      else {
        int up = 0, down = 0;
        if (i > 0)
          up = dp[i - 1][j];
        if (j > 0)
          down = dp[i][j - 1];
        dp[i][j] += up + down;
      }
    }
  }
  return dp[n - 1][m - 1];
}
