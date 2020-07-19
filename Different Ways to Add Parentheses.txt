class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0;i<input.size();i++){
            if (input[i] == '*'||input[i] == '+'||input[i] == '-'){
                vector<int> res1 = diffWaysToCompute(input.substr(0,i));
                vector<int> res2 = diffWaysToCompute(input.substr(i+1,input.size()-i-1));
                for (int j = 0;j<res1.size();j++)
                    for (int k = 0;k<res2.size();k++){
                        if (input[i] == '*') res.push_back(res1[j]*res2[k]);
                        if (input[i] == '+') res.push_back(res1[j]+res2[k]);
                        if (input[i] == '-') res.push_back(res1[j]-res2[k]);
                    }
            }
        }
        if (res.size() == 0) res.push_back(stoi(input));
        return res;
    }
};