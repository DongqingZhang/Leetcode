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
        int widthL = widthLeft(root);
        cout<<widthL<<endl;
        int width = widthL+widthRight(root)-1;
        cout<<width<<endl;
        if (width == -1) return vector<vector<int>>();
        vector<vector<int>> res(width,vector<int>());
        queue<TreeNode*> q;
        q.push(root);
        queue<int> ind;
        ind.push(widthL-1);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            int curInd = ind.front();
            res[curInd].push_back(tmp->val);
            q.pop();
            ind.pop();
            if (tmp->left){
                q.push(tmp->left);
                ind.push(curInd-1);
            }
            if (tmp->right){
                q.push(tmp->right);
                ind.push(curInd+1);
            }
        }
        return res;
    }
    int widthLeft(TreeNode* root){
        if (!root) return 0;
        if (!root->left&&!root->right) return 1;
        return max(widthLeft(root->left)+1,widthLeft(root->right)-1);
    }
    int widthRight(TreeNode* root){
        if (!root) return 0;
        if (!root->left&&!root->right) return 1;
        return max(widthRight(root->left)-1,widthRight(root->right)+1);
    }
};