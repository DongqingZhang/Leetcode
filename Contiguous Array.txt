class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int len = nums.size(), res = 0, sum = 0;
        if(len == 0) return 0;
        unordered_map<int,int> map;
        map[0] = -1;
        for(int i = 0;i<len;i++){
            sum += (nums[i]?1:-1);
            if(map.find(sum)!=map.end()){
                res = max(res, i - map[sum]);
            }
            else map[sum] = i;
        }
        return res;
    }
};