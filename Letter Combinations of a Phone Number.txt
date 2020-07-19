class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> units = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if (digits.size() == 0) return res;
        res.push_back("");
        for (int i = 0;i<digits.size();i++){
            if (digits[i]>'1'&&digits[i]<='9'){
                int len = res.size()>1?res.size():1;
                string tmp;
                for (int j = 0;j<len;j++){
                    tmp = res[j];
                    for (int k = 0;k<units[digits[i]-'2'].size()-1;k++){
                        tmp.push_back(units[digits[i]-'2'][k]);
                        res.push_back(tmp);
                        tmp.erase(tmp.begin()+tmp.size()-1);
                    }
                }
                for (int j = 0;j<len;j++){
                    res[j].push_back(units[digits[i]-'2'][units[digits[i]-'2'].size()-1]);
                }
            }
        }
        return res;
    }
};