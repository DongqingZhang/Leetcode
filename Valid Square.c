class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_map<int, int> map;
        map[(p2[0]-p1[0])*(p2[0]-p1[0])+(p2[1]-p1[1])*(p2[1]-p1[1])]++;
        map[(p3[0]-p1[0])*(p3[0]-p1[0])+(p3[1]-p1[1])*(p3[1]-p1[1])]++;
        map[(p4[0]-p1[0])*(p4[0]-p1[0])+(p4[1]-p1[1])*(p4[1]-p1[1])]++;
        map[(p3[0]-p2[0])*(p3[0]-p2[0])+(p3[1]-p2[1])*(p3[1]-p2[1])]++;
        map[(p4[0]-p2[0])*(p4[0]-p2[0])+(p4[1]-p2[1])*(p4[1]-p2[1])]++;
        map[(p4[0]-p3[0])*(p4[0]-p3[0])+(p4[1]-p3[1])*(p4[1]-p3[1])]++;
        if(map.size() != 2) return false;
        int mind = INT_MAX, maxd = INT_MIN;
        for(auto a:map){
            mind = min(mind, a.first);
            maxd = max(maxd, a.first);
        }
        if(maxd!=2*mind) return false;
        if(map[maxd]!=2) return false;
        if(map[mind]!=4) return false;
        return true;
    }
};