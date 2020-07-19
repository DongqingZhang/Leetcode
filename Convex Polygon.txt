class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        points.push_back(points[0]);
        points.push_back(points[1]);
        int len = points.size();
        pair<int,int> v1, v2;
        int direct = 0;
        for(int i = 0;i<len-2;i++){
            v1.first = points[i+1][0]-points[i][0];
            v1.second = points[i+1][1]-points[i][1];
            v2.first = points[i+2][0]-points[i+1][0];
            v2.second = points[i+2][1]-points[i+1][1];
            if((v1.first*v2.second-v2.first*v1.second)*direct < 0) return false;
            cout<<direct<<endl;
            if(v1.first*v2.second-v2.first*v1.second!=0) direct = v1.first*v2.second-v2.first*v1.second;
        }
        return true;
    }
};