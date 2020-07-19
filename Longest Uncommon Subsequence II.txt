class Solution {
public:
    struct myclass{
        bool operator() (string a, string b){
            return a.length()>b.length();
        }
    } myobj;
    int findLUSlength(vector<string>& strs) {
        if(strs.size() == 0) return -1;
        if(strs.size() == 1) return strs[0].length();
        sort(strs.begin(), strs.end(), myobj);
        for(int i = 0;i<strs.size();i++){
            bool flag = true;
            for(int j = 0;j<strs.size() && strs[j].length()>=strs[i].length();j++){
                if(j!=i && isSub(strs[j], strs[i])) flag = false;
            }
            if(flag) return strs[i].length();
        }
        return -1;
    }
    bool isSub(string a, string b){
        if(a.length() < b.length()) return false;
        int i = 0;
        for(auto c:a){
            if(c == b[i]) i++;
        }
        return i == b.length();
    }
};