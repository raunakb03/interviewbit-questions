#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> helper(int start, int end){
    vector<TreeNode*> res;
    if(start>end){
        res.push_back(NULL);
        return res;
    }

    for(int i=start; i<=end; i++){
        vector<TreeNode*> left= helper(start, i-1);
        vector<TreeNode*> right= helper(i+1, end);
        for(int j=0; j<left.size(); j++){
            for(int k=0; k<right.size(); k++){
                TreeNode* root = new TreeNode(i);
                root->left = left[j];
                root->right= right[k];
                res.push_back(root);
            }
        }
    }
    return res;
}
    
vector<TreeNode*> generateTrees(int A) {
    if(!A) return vector<TreeNode*> (0);
    return helper(1, A);

}
