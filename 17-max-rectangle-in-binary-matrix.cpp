#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
  int n = heights.size();
  stack<int> st;
  int left[n], right[n];
  for (int i = 0; i < n; i++) {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();
    if (st.empty())
      left[i] = 0;
    else
      left[i] = st.top() + 1;
    st.push(i);
  }
  while (!st.empty())
    st.pop();
  int maxarea = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && heights[st.top()] >= heights[i])
      st.pop();
    if (st.empty())
      right[i] = n - 1;
    else
      right[i] = st.top() - 1;
    st.push(i);
    maxarea = max(maxarea, (right[i] - left[i] + 1) * heights[i]);
  }
  return maxarea;
}

int maximalRectangle(vector<vector<int>> &A) {
  int n = A.size();
  int m = A[0].size();
  int ans = 0;
  vector<int> row(m + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!A[i][j])
        row[j] = 0;
      else
        row[j]++;
    }
    ans = max(ans, largestRectangleArea(row));
  }
  return ans;
}
