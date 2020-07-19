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
    unordered_map<int,int> map;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        helper(root);
        int maxv = INT_MIN;
        for(auto a:map){
            maxv = max(maxv,a.second);
        }
        vector<int> res;
        for(auto a:map){
            if(a.second == maxv) res.push_back(a.first);
        }
        return res;
    }
    int helper(TreeNode* root){
        if(!root) return 0;
        int tmp1 = helper(root->left);
        int tmp2 = helper(root->right);
        map[tmp1+tmp2+root->val]++;
        return tmp1+tmp2+root->val;
    }
};