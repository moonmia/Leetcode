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
    int depth;
    int maxDepth(TreeNode* node)
    {
        if(node == nullptr) return 0;
        
        int left = maxDepth(node->left);
        int right = maxDepth(node->right);
        
        depth = max(depth, left+right+1);
        return max(left, right)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        depth =1;
        maxDepth(root);
        return depth-1;
    }
};