class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> map;
        for(int i = 0;i<wall.size();i++){
            int sum = 0;
            for(int j = 0;j<wall[i].size()-1;j++){
                sum += wall[i][j];
                map[sum]++;
            }
        }
        int res = 0, line = 0;
        for(auto a:map){
            if(res < a.second){
                res = a.second;
                line = a.first;
            }
        }
        return wall.size()-res;
    }
};