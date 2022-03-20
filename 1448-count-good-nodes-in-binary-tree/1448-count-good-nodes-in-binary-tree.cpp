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
    int ans;
    void dfs(TreeNode* root, int mymax)
    {
        if(root == nullptr) return;
        if(root->val >= mymax) ans++;
        dfs(root->left, max(mymax, root->val));
        dfs(root->right, max(mymax, root->val));
    }
    int goodNodes(TreeNode* root) 
    {
        dfs(root, INT_MIN);
        return ans;
    }
};