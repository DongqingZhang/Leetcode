/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(Interval &a, Interval &b){
        return (a.end<=b.end);
    }
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, curind = 0, i = 0;
        while(curind < intervals.size()){
            i = curind;
            res++;
            while(curind < intervals.size() && intervals[curind].start < intervals[i].end) curind++;
        }
        return intervals.size()-res;
    }
};