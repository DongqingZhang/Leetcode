class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size() == 0) return res;
        string tmp;
        tmp.append(to_string(nums[0]));
        int count = 0;
        nums.push_back(nums[nums.size()-1]);
        for (int i = 1;i < nums.size();i++){
            if (nums[i] != nums[i-1] + 1){
                if (count > 0) tmp = tmp + "->" + to_string(nums[i-1]);
                res.push_back(tmp);
                tmp.clear();
                tmp.append(to_string(nums[i]));
                count = 0;
            }
            else count++;
        }
        return res;
    }
};