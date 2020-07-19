class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<const char*> waiting[128];
        for(auto &w:words) waiting[w[0]].push_back(w.c_str());
        for(auto s:S){
            auto tmp = waiting[s];
            waiting[s].clear();
            for(auto iter:tmp) waiting[*++iter].push_back(iter);
        }
        return waiting[0].size();
    }
};