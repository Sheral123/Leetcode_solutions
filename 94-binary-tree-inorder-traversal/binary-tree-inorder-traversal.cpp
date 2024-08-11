// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// using stack 

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> st;
//         vector<int> res;
//         while(root!=NULL || !st.empty()){
//             while(root!=NULL){
//                 st.push(root);
//                 root= root->left;
//             }
//             root=st.top();
//             st.pop();
//             res.push_back(root->val);
//             root =root->right;
//         }
//         return res;
//     }
// };



// using morris transversal for O(n) and O(1)

class Solution{
public:

    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root){
        vector<int> ans;
        helper(root, ans);
        return ans;

    }
};
