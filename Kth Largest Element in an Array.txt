class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>,std::greater<int>> h(nums.begin(),nums.begin()+k);
        int len = nums.size();
        for(int i=k;i<len;i++){
            if(nums[i]<h.top()) continue;
            h.push(nums[i]);
            h.pop();
        }
        return h.top();
    }
};