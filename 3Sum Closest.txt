class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        if (nums.size() < 3) return res;
        int final = nums[0]+nums[1]+nums[2];
        for (int i = 0;i<nums.size()-2;i++){
            if (i == 0||(i>0&&nums[i]!=nums[i-1])){
                int low = i+1, high = nums.size()-1, sum = target-nums[i];
                while(low < high){
                    if (nums[low]+nums[high] == sum){
                        return target;
                    }
                    else if(nums[low]+nums[high] > sum){
                        if (abs(nums[low]+nums[high] - sum)<res){
                            res = abs(nums[low]+nums[high] - sum);
                            final = nums[low]+nums[high]+nums[i];
                        }
                        high--;
                    }
                    else{
                        if (abs(nums[low]+nums[high] - sum)<res){
                            res = abs(nums[low]+nums[high] - sum);
                            final = nums[low]+nums[high]+nums[i];
                        }
                        low++;
                    }
                }
            }
        }
        return final;
    }
};