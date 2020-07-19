class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, end = 1, res = 0, len = nums.size();
        if(k<0) return 0;
        if(k == 0){
            while(end < len){
                if(nums[end] == nums[end-1]){
                    res++;
                    while(end<len && nums[end] == nums[end-1]) end++;
                }
                end++;
            }
            return res;
        }
        while(start < len && end < len){
            while(nums[end] - nums[start] < k){
                end++;
                while(end < len-1 && nums[end] == nums[end+1]) end++;
            }
            while(nums[end] - nums[start] > k){
                start++;
                while(start > 0 && nums[start] == nums[start-1]) start++;
            }
            if(nums[end] - nums[start] == k && end != start){
                res++;
                end++;
                while(end < len && nums[end] == nums[end+1]) end++;
                start++;
                while(start > 0 && nums[start] == nums[start-1]) start++;
                if(end == start) end++;
            }
        }
        return res;
    }
};