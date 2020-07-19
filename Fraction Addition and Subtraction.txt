class Solution {
public:
    string fractionAddition(string expression) {
        vector<pair<int,int>> s = spliter(expression);
        int denom = 1, nom = 0;
        for(auto a:s) denom = denom*a.second;
        for(auto a:s) nom += a.first*denom/a.second;
        if(nom == 0) return "0/1";
        int tmp = __gcd(min(abs(nom),abs(denom)), max(abs(nom),abs(denom)));
        nom/=tmp;
        denom/=tmp;
        return to_string(nom)+"/"+to_string(denom);
    }
    vector<pair<int,int>> spliter(string s){
        int cnt = -1;
        vector<string> res;
        vector<pair<int,int>> pairs;
        for(int i = 0;i<s.length();i++){
            if(i == 0 || (s[i] == '+' || s[i] == '-')){
                res.push_back("");
                cnt++;
                if((s[i] != '+' && s[i] != '-')&& i==0) res[cnt].push_back('+');
            }
            res[cnt].push_back(s[i]);
        }
        for(auto a:res) pairs.push_back(twoint(a));
        return pairs;
    }
    pair<int,int> twoint(string s){
        int i;
        for(i = 0;i<s.length();i++){
            if(s[i] == '/') break;
        }
        pair<int,int> res;
        res.first = stoi(s.substr(0,i));
        res.second = stoi(s.substr(i+1,s.length()-i-1));
        return res;
    }
};