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
    queue<pair<bool, TreeNode*>> q;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        q.push({true,root});
        bool state = true;
        vector<int> resLoc;
        while(!q.empty()){
            pair<bool,TreeNode*> tmp=q.front();
            q.pop();
            if (tmp.first != state){
                if (!state) reverse(resLoc.begin(),resLoc.end());
                res.push_back(resLoc);
                resLoc.clear();
            }
            state = tmp.first;
            resLoc.push_back(tmp.second->val);
            if(tmp.second->left) q.push({!state, tmp.second->left});
            if(tmp.second->right) q.push({!state, tmp.second->right});
        }
        if (!state) reverse(resLoc.begin(),resLoc.end());
        res.push_back(resLoc);
        return res;
    }
};