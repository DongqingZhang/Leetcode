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
    bool checkEqualTree(TreeNode* root) {
        unordered_map<int,int> set;
        int sum = checkSum(root, set);
        if(sum%2 != 0) return false;
        if(sum == 0) return set[sum]>1;
        if(set.count(sum/2)) return true;
        return false;
    }
    int sumTree(TreeNode* root){
        if(!root) return 0;
        return sumTree(root->left)+sumTree(root->right)+root->val;
    }
    int checkSum(TreeNode* root, unordered_map<int,int>& set){
        if(!root) return 0;
        int sum = root->val+checkSum(root->left, set)+checkSum(root->right, set);
        set[sum]++;
        return sum;
    }
};