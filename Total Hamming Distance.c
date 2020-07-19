class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int num = nums.size();
        if(num == 0) return 0;
        vector<int> cnt(32,0);
        for(int i = 0;i<num;i++){
            int tmp = nums[i];
            int j = 0;
            while(tmp){
                cnt[j++]+=(tmp%2);
                tmp>>=1;
            }
        }
        int res = 0;
        for(int i = 0;i<32;i++) res+=cnt[i]*(num-cnt[i]);
        return res;
    }
};