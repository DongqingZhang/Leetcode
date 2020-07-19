class Solution {
public:
    string solveEquation(string equation) {
        pair<string, string> s = splitlr(equation);
        vector<string> a = splitnum(s.first);
        vector<string> b = splitnum(s.second);
        pair<int,int> l = splitpair(a);
        pair<int,int> r = splitpair(b);
        int xcoef = l.first-r.first;
        int val = r.second-l.second;
        if(xcoef == 0){
            if(val!=0) return "No solution";
            else return "Infinite solutions";
        }
        return "x="+to_string((int)(val/xcoef));
    }
    pair<string, string> splitlr(string equation){
        pair<string, string> res;
        int i;
        for(i = 0;i<equation.length();i++){
            if(equation[i] == '=') break;
        }
        res.first = equation.substr(0,i);
        res.second = equation.substr(i+1,equation.length()-i-1);
        return res;
    }
    vector<string> splitnum(string s){
        int st = 0;
        vector<string> res;
        for(int i = 1;i<s.length();i++){
            if(s[i] == '+' || s[i] == '-'){
                res.push_back(s.substr(st,i-st));
                st = i;
            }
        }
        res.push_back(s.substr(st,s.length()-st));
        return res;
    }
    pair<int,int> splitpair(vector<string> s){
        pair<int,int> res = {0,0};
        for(auto a:s){
            if(a[a.length()-1] != 'x') res.second+=stoi(a);
            else{
                if(a.length() == 1) res.first+=1;
                else if(a.length() == 2 && a[0] == '-') res.first-=1;
                else if(a.length() == 2 && a[0] == '+') res.first+=1;
                else if(a.length() > 2 && a[0] == '+') res.first+=stoi(a.substr(1,a.length()-2));
                else res.first+=stoi(a.substr(0,a.length()-1));
            }
        }
        return res;
    }
};