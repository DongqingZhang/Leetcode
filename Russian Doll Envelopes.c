class Solution {
public:
    static bool myComp(const pair<int, int>& a, const pair<int, int>& b){
        if (a.first<b.first) return true;
        else if(a.first == b.first) return a.second>b.second;
        else return false;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myComp);
        vector<int> dp;
        for (int i = 0;i<envelopes.size();i++){
            auto iter = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
            if (iter == dp.end()) dp.push_back(envelopes[i].second);
            else *iter = envelopes[i].second;
        }
        return dp.size();
  }
};