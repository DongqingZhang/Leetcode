class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> myStr;
        for(int i=0;i<ransomNote.length();i++) myStr[ransomNote[i]]++;
        for(int i=0;i<magazine.length();i++){
           if (myStr.find(magazine[i])!=myStr.end()) myStr[magazine[i]]--; 
        }
        for(auto a:myStr){
            if (a.second>0) return false;
        }
        return true;
    }
};