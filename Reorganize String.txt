class Solution {
public:
    string reorganizeString(string S) {
        vector<int> map(26,0);
        for(auto a:S) map[a-'a']++;
        vector<pair<int,char>> cnts;
        for(int i = 0;i<26;i++) cnts.push_back({map[i],'a'+i});
        sort(cnts.rbegin(),cnts.rend());
        int len = S.length();
        if(cnts[0].first > (len+1)/2) return "";
        string res;
        for(auto a:cnts) for(int i = 0;i<a.first;i++) res.push_back(a.second);
        for(int i = 1;i < len;i+=2) res.insert(res.begin()+i,res[i+(len-1)/2]);
        return res.substr(0,len);
    }
};