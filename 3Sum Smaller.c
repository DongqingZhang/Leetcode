class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int len = nums.size(), cnt = 0;
        if(len<3) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<len-2;i++){
            int high = len-1, low = i+1;
            while(low<high){
                if(nums[i]+nums[low]+nums[high]<target){
                    cnt+=(high-low);
                    low++;
                }
                else high--;
            }
        }
        return cnt;
    }
};