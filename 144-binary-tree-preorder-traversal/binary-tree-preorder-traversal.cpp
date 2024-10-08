        // vector<int> nodes;
        // stack<TreeNode*> todo;
        // while (root || !todo.empty()) {
        //     if (root) {
        //         nodes.push_back(root -> val);
        //         if (root -> right) {
        //             todo.push(root -> right);
        //         }
        //         root = root -> left;
        //     } else {
        //         root = todo.top();
        //         todo.pop();
        //     }
        // }
        // return nodes;


class Solution {
public:
        
    void helper(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> ans;
        helper(root, ans);
        return ans;

    }
};