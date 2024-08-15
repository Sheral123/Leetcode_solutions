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

   // int maxh(TreeNode* root){
    //     if(root == NULL) return ;
    //     return 1+ max(maxh(root->left),maxh(root->right));
    // }
   
    // void inorder(TreeNode* root, bool & ans){
    //     if(root!=NULL){
    //         inorder(root->left,ans);
    //         int lh =maxh(root->left);
    //         int rh =maxh(root->right);
    //         if(abs(lh-rh)>1){
    //             ans= ans&&false;
    //         }
    //         inorder(root->right,ans);        
    //     }
 
    // }

    // bool isBalanced(TreeNode* root) {
    //     bool ans=true;
    //     inorder(root,ans);
    //     return ans;
    // }



// class Solution {
// public:
//  // O(n2) time complexity
//     int maxh(TreeNode* root){
//         if(!root) return 0;
//         return 1 + max(maxh(root->left), maxh(root->right));
//     }

//     bool isBalanced(TreeNode* root) {
//         if(!root) return true;
//         int lh= maxh(root->left);
//         int rh= maxh(root->right);
        
//         return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
//     }  
    
 
// };



class Solution {
public:
 // O(n) time complexity
    int checkh(TreeNode* root){
        if(!root) return 0;
        int lh= checkh(root->left);
        if(lh == -1 ) return -1;
        int rh= checkh(root->right);
        if(rh == -1 ) return -1;
        if(abs(lh - rh) > 1) return -1;
        return 1+ max(lh, rh);

    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return (checkh(root) == -1) ? false : true;
    }  
    
 
};