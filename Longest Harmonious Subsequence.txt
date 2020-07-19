class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        for(auto a:nums) map[a]++;
        int res = 0;
        for(auto a:map){
            if(map.find(a.first+1)!=map.end()) res = max(res, a.second+map[a.first+1]);
        }
        return res;
    }
};