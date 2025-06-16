/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int cnt = 0;
    int res = INT_MAX;

    void inorder_dfs(TreeNode* root, int k){
        if(!root) return;

        inorder_dfs(root->left, k);
        cnt++;
        if(cnt == k) res = root->val;

        inorder_dfs(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder_dfs(root, k);
        return res;
    }
};