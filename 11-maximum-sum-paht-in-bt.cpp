#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// find the path in the binary with the maximum sum
int f(TreeNode *root, int &ans) {
  if (!root)
    return 0;
  int left = max(0, f(root->left, ans));
  int right = max(0, f(root->right, ans));

  ans = max(ans, left + right + root->val);
  return max(left, right) + root->val;
}

int maxPathSum(TreeNode *A) {
    int ans= INT_MIN;
    f(A, ans);
    return ans;
}
