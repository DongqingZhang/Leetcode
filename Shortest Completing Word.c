class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> stats(26,0);
        for(auto a:licensePlate){
            if(a >= 'a' && a <= 'z') stats[a-'a']++;
            if(a >= 'A' && a <= 'Z') stats[a-'A']++;
        }
        int len = INT_MAX;
        string res = words[0];
        for(auto word:words){
            if(len > word.length() && matches(word,stats)){
                len = word.length();
                res = word;
            }
        }
        return res;
    }
    bool matches(string word, vector<int> stats){
        for(auto a:word){
            if(a >= 'A' && a <= 'Z'){
                int ind = a-'A';
                stats[ind]--;
            }
            else if(a >= 'a' && a <= 'z'){
                int ind = a-'a';
                stats[ind]--;
            }
        }
        for(auto a:stats){
            if(a > 0) return false;
        }
        return true;
    }
};