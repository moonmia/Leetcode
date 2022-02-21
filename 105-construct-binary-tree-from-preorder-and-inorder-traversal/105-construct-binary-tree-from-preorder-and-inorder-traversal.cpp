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
private:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& preorder, int preorderBegin, int preorderEnd)
    {
        if(preorderBegin == preorderEnd) return NULL;
        
        int rootValue = preorder[preorderBegin];
        TreeNode* root = new TreeNode(rootValue);
        
        if(preorderEnd - preorderBegin ==1) return root;
        
        int delimiterIndex;
        for(delimiterIndex = inorderBegin; delimiterIndex < inorderEnd; delimiterIndex++)
        {
            if(inorder[delimiterIndex] == rootValue) break;
        }
        
        int leftInorderBegin = inorderBegin;
        int leftInorderEnd = delimiterIndex;
        
        int rightInorderBegin = delimiterIndex+1;
        int rightInorderEnd = inorderEnd;
        
        int leftPreorderBegin = preorderBegin +1;
        int leftPreorderEnd = preorderBegin +1 + delimiterIndex - inorderBegin;
        
        int rightPreorderBegin = preorderBegin +1 + (delimiterIndex - inorderBegin);
        int rightPreorderEnd = preorderEnd;
        
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, preorder, leftPreorderBegin, leftPreorderEnd);
        
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, preorder, rightPreorderBegin, rightPreorderEnd);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(inorder.size() == 0 || preorder.size() == 0) return NULL;
        
        return traversal(inorder, 0, inorder.size(), preorder, 0, preorder.size());
    }
};