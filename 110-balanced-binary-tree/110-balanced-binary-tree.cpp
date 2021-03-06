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
    int height(TreeNode* node)
    {
        if(node == nullptr) return 0;
        int left = height(node->left);
        int right = height(node->right);
        
        if(left == -1 || right == -1 || abs(right-left) > 1)
        {
            return -1;
        }
        else
        {
            return max(left, right)+1;
        }
    }
    bool isBalanced(TreeNode* root) 
    {
        return height(root) >= 0;
    }
};