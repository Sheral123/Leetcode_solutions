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

    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ans;
        helper(root, ans);
        return ans;

    }
    

};    

/*

    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* last = NULL;
        stack<TreeNode*> st;
        vector<int> ans;

        while(root || !st.empty()){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                TreeNode* node = st.top();
                if(node->right && last != node->right ){
                    root = node->right;
                }
                else{
                    ans.push_back(node->val);
                    last=node;
                    st.pop();
                }
            }
        }
        return ans;
        
    }
};
*/