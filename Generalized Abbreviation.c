class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        if (word.length() == 0){
            res.push_back("");
            return res;
        }
        helper(word, res);
        return res;
    }
    void helper(string word, vector<string>& res){
        if (word.length() == 1){
            res.push_back(word);
            res.push_back("1");
            return;
        }
        helper(word.substr(0,word.length()-1), res);
        int len = res.size();
        for (int i=0;i<len;i++){
            string tmp = res[i];
            res.push_back(tmp.append(word.substr(word.size()-1,1)));
            if(res[i][res[i].length()-1]>='0'&&res[i][res[i].length()-1]<='9'){
                int cnt = 0;
                while(cnt<=res[i].length()-1&&res[i][res[i].length()-1-cnt]>='0'&&res[i][res[i].length()-1-cnt]<='9') cnt++;
                int num = stoi(res[i].substr(res[i].length()-cnt,cnt));
                res[i].erase(res[i].length()-cnt,cnt);
                res[i].append(to_string(num+1));
            }
            else res[i].push_back('1');
        }
    }
};