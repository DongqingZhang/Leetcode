class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int len = points.size(), res = 0;
        for(int i = 0;i<len;i++){
            unordered_map<int, int> map;
            for(int j = 0;j<len;j++){
                if(j == i) continue;
                map[(points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second)]++;
            }
            for(auto a:map) res += a.second*a.second-a.second;
        }
        return res;
    }
};