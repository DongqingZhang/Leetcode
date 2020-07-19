class ValidWordAbbr {
public:
    unordered_map<string, vector<string>> abbrs;
    ValidWordAbbr(vector<string> dictionary) {
        for(auto a:dictionary) abbrs[abbr(a)].push_back(a);
    }
    bool isUnique(string word) {
        string ab = abbr(word);
        if(abbrs.find(ab)==abbrs.end()) return true;
        for(auto a:abbrs[ab]){
            if(a.compare(word) != 0) return false;
        }
        return true;
    }
    string abbr(string word){
        int len = word.length();
        if(len <= 2) return word;
        return word[0]+to_string(len-2)+word[len-1];
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */