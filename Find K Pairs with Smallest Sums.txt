class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        auto cmp = [&nums1, &nums2](pair<int, int> &a,pair<int, int> &b){
            return nums1[a.first]+nums2[a.second]>nums1[b.first]+nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        q.push({0,0});
        if (nums1.size() == 0||nums2.size() == 0||k <= 0) return res;
        while (k-- && q.size() != 0){
            auto ind = q.top();q.pop();
            res.push_back({nums1[ind.first],nums2[ind.second]});
            if (ind.second+1<nums2.size()) q.push({ind.first,ind.second+1});
            if (ind.second == 0 && ind.first+1<nums1.size()) q.push({ind.first+1,ind.second});
        }
        return res;
    }
};