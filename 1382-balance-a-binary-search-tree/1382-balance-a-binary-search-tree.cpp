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
    vector<int> tree;
    void dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
           return; 
        }
        dfs(root->left);
        tree.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* constructBBST(int left, int right)
    {
        if(left > right) return nullptr;
        int mid = (left+right)/2;
        TreeNode* root = new TreeNode(tree[mid]);
        root->left = constructBBST(left, mid-1);
        root->right = constructBBST(mid+1, right);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) 
    {
        dfs(root);   
        return constructBBST(0, tree.size()-1);
    }
};