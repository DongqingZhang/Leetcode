class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> map;
        for(auto a:answers) map[a]++;
        int res = 0;
        for(auto a:map){
            int group = 0;
            if(a.second%(a.first+1) == 0) group = a.second/(a.first+1);
            else group = a.second/(a.first+1)+1;
            res += group*(a.first+1);
        }
        return res;
    }
};