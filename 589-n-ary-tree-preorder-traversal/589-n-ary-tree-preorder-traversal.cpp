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
    void traversal(Node* node, vector<int>& vec)
    {
        if(node == NULL) return;
        vec.push_back(node->val);
        for(int i=0; i<node->children.size(); i++)
        {
            traversal(node->children[i], vec);
        }
    }
    vector<int> preorder(Node* root) 
    {
        vector<int>result;
        traversal(root, result);
        return result;
    }
};