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
    string dfs(TreeNode* root, vector<TreeNode*>& res, unordered_map<string, int>& mp){
        if(root == NULL) return "#";
        string str = to_string(root->val) + "-" + dfs(root->left, res, mp) + "-" + dfs(root->right, res, mp);
        if(mp[str] == 1){
            res.push_back(root);
        }
        mp[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        vector<TreeNode*>res; 
        unordered_map<string, int>mp;
        dfs(root, res, mp);
        return res;
    }
};