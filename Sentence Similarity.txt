class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int len1 = words1.size(), len2 = words2.size();
        if(len1 != len2) return false;
        for(int i = 0;i < len1;i++){
            if(!isSimilar(pairs, words1[i], words2[i])) return false;
        }
        return true;
    }
    bool isSimilar(vector<pair<string, string>> pairs, string s1, string s2){
        if(s1 == s2) return true;
        pair<string, string> words1, words2;
        words1.first = s1;
        words1.second = s2;
        words2.first = s2;
        words2.second = s1;
        if(find(pairs.begin(),pairs.end(),words1)!=pairs.end() || find(pairs.begin(),pairs.end(),words2)!=pairs.end()){
            return true;
        }
        else return false;
    }
};