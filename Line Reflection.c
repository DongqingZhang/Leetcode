class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int minx = INT_MAX,maxx=INT_MIN;
        unordered_set<string> map;
        for (int i = 0;i<points.size();i++)
            map.emplace(to_string(points[i].first)+"a"+to_string(points[i].second));
        for (int i = 0;i<points.size();i++){
            if (points[i].first<minx) minx = points[i].first;
            if (points[i].first>maxx) maxx = points[i].first;
        }
        long mid = maxx+minx;
        for (int i = 0;i<points.size();i++){
            if (map.find(to_string(mid-points[i].first)+"a"+to_string(points[i].second))==map.end()) return false;
        }
        return true;
    }
};