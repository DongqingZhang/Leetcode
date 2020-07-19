class Solution {
public:
    string boldWords(vector<string>& words, string S) {
        string res = S;
        for(auto a:words){
            for(int i = 0;i<S.length()-a.length()+1;i++){
                if(S.substr(i,a.length()).compare(a) == 0) uppercase(res,i,i+a.length()-1);
            }
        }
        string res2;
        for(int i = 0;i<S.length();i++){
            if(res[i] >= 'a') res2.push_back(res[i]);
            if(res[i] <= 'Z'){
                if(i == 0 || res[i-1] >= 'a') res2.append("<b>");
                res2.push_back(S[i]);
                if(i == S.length()-1 || res[i+1]>='a') res2.append("</b>");
            }
        }
        return res2;
    }
    void uppercase(string& res, int a, int b){
        for(int i = a;i<=b;i++) if(res[i] >= 'a') res[i] -= ('a'-'A');
    }
};