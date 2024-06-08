#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* buildTree(vector<int>& arr, int i, int j){
    if(i>j) return NULL;
    int mid= (i+j)/2;
    TreeNode* root= new TreeNode(arr[mid]);
    TreeNode* left= buildTree(arr, i, mid-1);
    TreeNode* right= buildTree(arr, mid+1, j);
    root->left= left;
    root->right= right;
    return root;
}

TreeNode *sortedListToBST(ListNode *A) {
    vector<int> arr;
    ListNode* temp= A;
    while(temp){
        arr.push_back(temp->val);
        temp= temp->next;
    }
    TreeNode* ans= buildTree(arr, 0, arr.size()-1);
    return ans;
}
