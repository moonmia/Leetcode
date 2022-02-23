/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*>que;
        vector<vector<int>>result;
        
        if(root != NULL) que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            vector<int>path;
            
            for(int i=0; i<size; i++)
            {
                Node* node = que.front();
                que.pop();
                path.push_back(node->val);
                for(int i=0; i<node->children.size(); i++)
                {
                    if(node->children[i])
                    {
                        que.push(node->children[i]);
                    }
                }
            }
            result.push_back(path);
        }
        return result;
    }
};