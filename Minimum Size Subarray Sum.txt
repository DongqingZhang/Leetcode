class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int len = nums.size(), sum = 0, cnt=0, minL = 0, curL = 0;
        int start = -1;
        while(start<len-1&&sum < s) sum+=nums[++start];
        if(sum < s) return 0;
        minL = start+1;
        curL = minL;
        sum -= nums[start];
        for(int i = start;i < len;i++){
            sum+=nums[i];
            curL++;
            while(sum-nums[i-curL+1]>=s){
                sum -= nums[i-curL+1];
                curL--;
            }
            minL = min(minL,curL);
        }
        return minL;
    }
};