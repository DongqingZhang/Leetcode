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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        unordered_map<int, vector<int>> myMap;
        queue<TreeNode*> q;
        q.push(root);
        queue<int> ind;
        ind.push(0);
        int minInd=0, maxInd=0, curInd = 0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            int indTmp = ind.front();
            myMap[indTmp].push_back(tmp->val);
            maxInd = max(maxInd,indTmp);
            minInd = min(minInd,indTmp);
            q.pop();
            ind.pop();
            if (tmp->left){
                q.push(tmp->left);
                ind.push(indTmp-1);
            }
            if (tmp->right){
                q.push(tmp->right);
                ind.push(indTmp+1);
            }
        }
        for (int i=minInd;i<=maxInd;i++){
            res.push_back(myMap[i]);
        }
        return res;
    }
};