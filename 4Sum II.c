class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        for(auto a:A)
            for(auto b:B){
                map[a+b]++;
            }
        int res = 0;
        for(auto c:C)
            for(auto d:D){
                if(map.find(-c-d) != map.end()) res += map[-c-d];
            }
        return res;
    }
};