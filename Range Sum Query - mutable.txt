class segmentTreeNode{
public:
    int start, end, sum;
    segmentTreeNode *left, *right;
    segmentTreeNode(int s, int e);
};
segmentTreeNode::segmentTreeNode(int s, int e){
    start = s;
    end = e;
    sum = 0;
    left = nullptr;
    right = nullptr;
}
class NumArray {
public:
    segmentTreeNode* myRoot = nullptr;
    int update(segmentTreeNode* root, int i, int val){
        if (!root) return 0;
        int diff = 0;
        if (root->start == i && root->end == i){
            int diff = val-root->sum;
            root->sum = val;
            return diff;
        }
        int mid = root->start+(root->end-root->start)/2;
        if (mid<i) diff = update(root->right, i, val);
        else diff = update(root->left, i, val);
        root->sum += diff;
        return diff;
    }
    int computeSum(segmentTreeNode* root, int i, int j){
        if (!root) return 0;
        if (root->start == i&&root->end == j) return root->sum;
        int mid = root->start+(root->end-root->start)/2;
        if (mid < i) return computeSum(root->right, i, j);
        if (mid >= j) return computeSum(root->left, i, j);
        return computeSum(root->left, i, mid)+computeSum(root->right, mid+1, j);
    }
    segmentTreeNode* helper(vector<int>& nums, int start, int end){
        if (start > end) return nullptr;
        segmentTreeNode* root = new segmentTreeNode(start, end);
        if (start == end){root->sum = nums[start]; return root;}
        root->left = helper(nums, start, start+(end-start)/2);
        root->right = helper(nums, start+(end-start)/2+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
    NumArray(vector<int> &nums) {
        myRoot = helper(nums, 0, nums.size()-1);
    }
    void update(int i, int val) {
        update(myRoot, i, val);
    }

    int sumRange(int i, int j) {
        return computeSum(myRoot, i, j);
    }
    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);