class Solution {
public:
    static bool mycompare(pair<int,int>& a, pair<int,int>& b){
        if(a.first > b.first) return true;
        if(a.first < b.first) return false;
        return a.second < b.second;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), mycompare);
        vector<pair<int,int>> res;
        for(auto a:people) res.insert(res.begin()+a.second,a);
        return res;
    }
};