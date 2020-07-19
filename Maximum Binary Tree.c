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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        return helper(nums, 0, len-1);
    }
    TreeNode* helper(vector<int>& nums, int a, int b){
        if(a > b) return nullptr;
        if(a == b){
            TreeNode* node = new TreeNode(nums[a]);
            return node;
        }
        int ind = a, maxV = nums[a];
        for(int i = a;i <= b;i++){
            if(nums[i] > maxV){
                maxV = nums[i];
                ind = i;
            }
        }
        TreeNode* node = new TreeNode(nums[ind]);
        node->left = helper(nums, a, ind-1);
        node->right = helper(nums, ind+1, b);
        return node;
    }
};