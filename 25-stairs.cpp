#include <bits/stdc++.h>
using namespace std;

// can  take one or two steps at a time
// find the number of ways to react the top
int climbStairs(int A) {
  vector<int> dp(A + 1, 0);
  for (int i = A; i >= 0; i--) {
    if (i == A) {
      dp[i] = 1;
    } else {
      dp[i] += dp[i + 1];
      if (i + 2 <= A) {
        dp[i] += dp[i + 2];
      }
    }
  }
  return dp[0];
}
