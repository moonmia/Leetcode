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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        queue<TreeNode*>que;
        if(root != nullptr) que.push(root);
        vector<vector<int>>result;
        int level=0;
        
        while(!que.empty())
        {
            int size = que.size();
            deque<int>temp;
            
            for(int i=0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                
                if(level%2 ==0)
                {
                    temp.push_back(node->val);
                }
                else
                {
                    temp.push_front(node->val);
                }
            }
            result.push_back(vector<int>(temp.begin(), temp.end()));
            level++;
        }
        return result;
    }
};