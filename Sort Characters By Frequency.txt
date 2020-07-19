class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        vector<string> bucket(s.size(),"");
        for(int i = 0;i<s.length();i++) map[s[i]]++;
        for(auto a:map){
            bucket[a.second-1].append(a.second,a.first);
        }
        string res;
        for(int i = s.size()-1;i>=0;i--){
            if(bucket[i].length()!=0) res.append(bucket[i]);
        }
        return res;
    }
};