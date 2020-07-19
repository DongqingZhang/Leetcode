class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<pair<int, int>> res;
        pair<int, int> tmp;
        tmp.first = 1;
        tmp.second = 0;
        res.push_back(tmp);
        for (int i = 1;i < len;i++){
            tmp.first = 1;
            tmp.second = 0;
            for (int j = 0;j < i;j++){
                if (nums[i] > nums[j] && res[j].first >= tmp.first && res[j].second <= 0){ tmp.first = res[j].first+1; tmp.second = 1;}
                if (nums[i] < nums[j] && res[j].first >= tmp.first && res[j].second >= 0){ tmp.first = res[j].first+1; tmp.second = -1;}
            }
            res.push_back(tmp);
        }
        int wl = 1;
        for (int i = 0;i<nums.size();i++){
            if (wl<res[i].first) wl = res[i].first;
        }
        return wl;
    }
};