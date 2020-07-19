class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        int minv = INT_MAX;
        for(int i = 0;i<list1.size();i++) map[list1[i]] = -i-1;
        for(int i = 0;i<list2.size();i++){
            if(map.find(list2[i])!=map.end()){
                map[list2[i]] = -map[list2[i]]+i+1;
                minv = min(minv,map[list2[i]]);
            }
        }
        vector<string> res;
        for(auto a:map){
            if(minv == a.second) res.push_back(a.first);
        }
        return res;
    }
};