/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        queue<Node*>que;
        if(root != nullptr) que.push(root);
        
        while(!que.empty())
        {
            int size = que.size();
            
            Node* node;
            Node* nodePrev;
            
            for(int i=0; i<size; i++)
            {
                if(i==0)
                {
                    nodePrev = que.front();
                    que.pop();
                    node = nodePrev;
                }
                else
                {
                    node = que.front();
                    que.pop();
                    nodePrev->next = node;
                    nodePrev = nodePrev->next;
                }
                if(node->left) que.push(node->left);
                if(node->right)que.push(node->right);
            }
            nodePrev->next = NULL;
        }
        return root;
    }
};