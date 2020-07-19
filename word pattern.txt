class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> myMap;
        istringstream in(str);
        int i = 0;
        for (string buff; in>>buff;++i){
            if (myMap.find(pattern[i]) != myMap.end()){
                if (myMap[pattern[i]]!=buff) return false;
            }
            else{
                for (unordered_map<char, string>::iterator it = myMap.begin(); it!=myMap.end();it++){
                    if (it->second==buff) return false;
                }
                myMap[pattern[i]] = buff;
            }
        }
        return i == pattern.size();
    }
};