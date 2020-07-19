class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        if (len == 0) return 0;
        int res = duration, timepoint = timeSeries[0]+duration;
        if (len == 1) return duration;
        for(int i = 1;i < len;i++){
            if(timepoint < timeSeries[i]) res+=duration;
            else if(timepoint < timeSeries[i]+duration) res+=(timeSeries[i]+duration-timepoint);
            timepoint = max(timepoint, timeSeries[i]+duration);
        }
        return res;
    }
};