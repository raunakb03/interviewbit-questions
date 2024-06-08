#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode *A) {
  vector<vector<int>> ans;
  queue<TreeNode *> q;
  q.push(A);
  while (!q.empty()) {
    int size = q.size();
    vector<int> temp;
    while (size--) {
      auto top = q.front();
      q.pop();
      if (top->val == -1)
        continue;
      temp.push_back(top->val);
      if (top->left && top->left->val != -1)
        q.push(top->left);
      if (top->right && top->right->val != -1)
        q.push(top->right);
    }
    ans.push_back(temp);
  }
  return ans;
}
