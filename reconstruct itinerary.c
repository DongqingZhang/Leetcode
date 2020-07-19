class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto a: tickets)
            m[a.first].insert(a.second);
        dfs(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    void dfs(unordered_map<string, multiset<string>> &m, string t, vector<string> &res){
        while (m[t].size()){
            string t1 = *m[t].begin();
            m[t].erase(m[t].begin());
            dfs(m, t1, res);
        }
        res.push_back(t);
    }
};