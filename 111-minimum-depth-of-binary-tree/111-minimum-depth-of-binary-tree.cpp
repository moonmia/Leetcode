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
    int minDepth(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        
        if(root->left == nullptr && root->right == nullptr) return 1;
        int depth=INT_MAX;
        
        if(root->left) depth = min(minDepth(root->left), depth);
        if(root->right) depth = min(minDepth(root->right), depth);
        
        return depth+1;
    }
};