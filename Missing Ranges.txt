class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int i = -1;
        vector<string> res;
        for(int i = 0;i <= nums.size();i++){
            int lt = (i == 0)? lower-1:nums[i-1];
            int ht = (i == nums.size())? upper+1:nums[i];
            addRange(res,lt,ht);
        }
        return res;
    }
    void addRange(vector<string>& res, int lt, int ht){
        if(ht - lt <= 1) return;
        string tmp;
        tmp += to_string(lt+1);
        if(ht - lt > 2) tmp += ("->"+to_string(ht-1));
        res.push_back(tmp);
    }
};