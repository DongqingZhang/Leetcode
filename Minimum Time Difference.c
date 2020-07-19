class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, len = timePoints.size();
        vector<int> conv;
        for(int i = 0;i < len;i++) conv.push_back(helper(timePoints[i]));
        sort(conv.begin(),conv.end());
        for(int i = 1;i < len;i++) res = min(res,conv[i] - conv[i-1]);
        return min(res,24*60-conv[len-1]+conv[0]);
    }
    int helper(string p){
        return stoi(p.substr(0,2))*60+stoi(p.substr(3,2));
    }
};