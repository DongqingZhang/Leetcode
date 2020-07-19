class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int cnt = 0, maxLen = 0;
        for(int i = 0;i<len;i++){
            if(nums[i] == 1){
                if(i == 0 || nums[i-1] == 0) cnt=0;
                cnt++;
            }
            else{
                if(i>0&&nums[i-1] == 1) maxLen = max(maxLen, cnt);
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
};