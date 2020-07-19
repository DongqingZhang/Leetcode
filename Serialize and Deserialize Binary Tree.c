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
        pair<int, string> res = mySerialize(root);
        return res.second;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.length();
        if(len == 0) return nullptr;
        TreeNode* root = new TreeNode(0);
        int start = 0, end = 0;
        while(data[end++]!='#');
        root->val = stoi(data.substr(0,end-1));
        start = end;
        while(data[end++]!=',');
        int lenLeft = stoi(data.substr(start, end-start-1));
        root->left = deserialize(data.substr(end, lenLeft));
        root->right = deserialize(data.substr(end+lenLeft, len-end-lenLeft));
        return root;
    }
    pair<int, string> mySerialize(TreeNode* root){
        if(!root) return {0,""};
        string res;
        res.append(to_string(root->val));
        res.push_back('#');
        pair<int, string> left = mySerialize(root->left);
        res.append(to_string(left.first)+","+left.second);
        pair<int, string> tmp = mySerialize(root->right);
        res.append(tmp.second);
        return {int(res.length()),res};
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));