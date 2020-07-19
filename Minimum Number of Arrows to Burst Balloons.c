class Solution {
private:
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second<b.second;
    }
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end(), comp);
        int res = 0;
        long int e = INT_MIN;
        e -= 1;
        for(int i = 0;i<points.size();i++){
            if(points[i].first > e){
                e = points[i].second;
                res++;
            }
        }
        return res;
    }
};