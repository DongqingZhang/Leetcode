/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    unordered_map<string, int> map;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root, map, res);
        return res;
    }
    string helper(TreeNode* root, unordered_map<string, int>& map, vector<TreeNode*>& res){
        if(!root) return "#";
        string s = to_string(root->val)+","+helper(root->left, map, res)+","+helper(root->right, map, res);
        if(map.find(s)!=map.end() && map[s]==1) {
            res.push_back(root);
            map[s]++;
        }
        else if(map.find(s)==map.end()) map[s] = 1;
        return s;
    }
};