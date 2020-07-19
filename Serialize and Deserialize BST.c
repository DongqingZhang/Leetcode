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
        if(!root) return "";
        string res;
        res.append(to_string(root->val));
        res.push_back('#');
        res.append(serialize(root->left)+serialize(root->right));
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length(), start = 0, end = 0, tmp = 0;
        if(len == 0) return nullptr;
        TreeNode* res = new TreeNode(0);
        while(data[end++]!='#');
        res->val = stoi(data.substr(0, end-1));
        start = end;
        int start0 = end;
        while(end < len){
            while(data[end++]!='#');
            tmp = stoi(data.substr(start, end-start-1));
            if(tmp > res->val) break;
            start = end;
        }
        res->left = deserialize(data.substr(start0, start-start0));
        res->right = deserialize(data.substr(start, len-start));
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));