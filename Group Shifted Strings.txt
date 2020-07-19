class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map <string, vector<string>> myMap;
        for (int i = 0;i<strings.size();i++){
            myMap[getCode(strings[i])].push_back(strings[i]);
        }
        vector<vector<string>> res;
        for (auto a:myMap){
            sort(a.second.begin(),a.second.end());
            res.push_back(a.second);
        }
        return res;
    }
    string getCode(string input){
        string output;
        for (int i = 0;i<input.length();i++){
            output.push_back(input[i]-input[0]>=0?input[i]-input[0]:input[i]-input[0]+26);
        }
        return output;
    }
};