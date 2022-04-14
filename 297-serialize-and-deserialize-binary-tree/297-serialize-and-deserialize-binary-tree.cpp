/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#";
        return to_string(root->val) + " " + serialize(root->left) + " "+ serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* myDeserialize(istringstream &ss){
        string temp;
        ss >> temp;
        if(temp == "#") return NULL;
        TreeNode* node = new TreeNode(stoi(temp));
        node->left = myDeserialize(ss);
        node->right = myDeserialize(ss);
        return node;
    }
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return myDeserialize(ss);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));