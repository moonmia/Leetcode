/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    unordered_map<int, TreeNode*> parents;
    vector<int>result;
    
    void findParent(TreeNode* node)
    {
        if(node->left != nullptr)
        {
            parents[node->left->val] = node;
            findParent(node->left);
        }
        if(node->right != nullptr)
        {
            parents[node->right->val] = node;
            findParent(node->right);
        }
    }
    
    void dfs(TreeNode* node, TreeNode* from, int depth, int k)
    {
        if(node == nullptr) return;
        
        if(depth == k)
        {
            result.push_back(node->val);
            return;
        }
        
        if(node->left != from)
        {
            dfs(node->left, node, depth+1, k);
        }
        
        if(node->right != from)
        {
            dfs(node->right, node, depth+1, k);
        }
        
        if(parents[node->val] != from)
        {
            dfs(parents[node->val], node, depth+1, k);
        }
    }
    
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        findParent(root);
        dfs(target, nullptr, 0, k);
        
        return result;
    }
};