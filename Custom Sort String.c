class Solution {
public:
    string customSortString(string S, string T) {
        vector<int> cnt(26,0);
        for(auto a:T) cnt[a-'a']++;
        string res;
        for(auto a:S){
            for(int i = 0;i<cnt[a-'a'];i++)
                res.push_back(a);
            cnt[a-'a'] = 0;
        }
        for(int i = 0;i<26;i++){
            for(int j = 0;j<cnt[i];j++)
                res.push_back(i+'a');
        }        
        return res;
    }
};