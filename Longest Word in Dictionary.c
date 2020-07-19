class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> set;
        string res = "";
        for(auto a:words){
            if(a.length() == 1 || set.count(a.substr(0,a.length()-1))){
                res = a.length()>res.length()?a:res;
                set.insert(a);
            }
        }
        return res;
    }
};