class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        long l = 0, r = 0, mid = 0;
        for(int i = 0;i < len;i++){
            l = max(l, (long)nums[i]);
            r += nums[i];
        }
        while(l < r){
            mid = (l+r)/2;
            if(valid(nums, mid, m)) r = mid;
            else l = mid+1;
        }
        return (int)l;
    }
    bool valid(vector<int>& nums, long val, int m){
        int cnt = 1, len = nums.size();
        long sum = 0;
        for(int i = 0;i<len;i++){
            sum+=nums[i];
            if(sum > val){
                sum = nums[i];
                cnt++;
            }
            if(cnt>m) return false;
        }
        return true;
    }
};