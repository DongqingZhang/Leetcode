class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.insert(nums.begin(),1);
        vector<vector<int>> res;
        if (nums.size() == 1) return {};
        res.push_back({1});
        for (int i = 1;i < nums.size();i++){
            vector<int> tmp;
            for (int j = i-1;j >= 0;j--){
                if (nums[i]%nums[j] == 0 && tmp.size() < res[j].size()) tmp = res[j];
            }
            tmp.push_back(nums[i]);
            res.push_back(tmp);
        }
        vector<int> tmp;
        int len = 0;
        for (int i = 0;i < res.size();i++){
            if (len < res[i].size()){
                len = res[i].size();
                tmp = res[i];
            }
        }
        tmp.erase(tmp.begin());
        return tmp;
    }
};