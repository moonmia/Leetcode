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
        int min_depth=0;
        if (root == nullptr) return 0;
        
        if(root->left == 0 && root->right == 0) return 1;
        
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty())
        {
            
            int size =que.size();
            min_depth++;
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(!node->left && !node->right)
                {
                    return min_depth;
                }
            }
        }
        return min_depth;
    }
};