class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size() != words2.size()) return false;
        unordered_map<string, vector<string>> map;
        for(auto a:pairs){
            map[a.first].push_back(a.second);
            map[a.second].push_back(a.first);
        }
        for(int i = 0;i<words1.size();i++){
            unordered_set<string> set;
            if(!isSimi(words1[i], words2[i], set, map)) return false;
        }
        return true;
    }
    bool isSimi(string w1, string w2, unordered_set<string>& set, unordered_map<string, vector<string>>& map){
        if(w1 == w2) return true;
        set.emplace(w1);
        for(auto a:map[w1]){
            if(!set.count(a) && isSimi(a,w2,set,map)) return true;
        }
        return false;
    }
};