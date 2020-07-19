class Solution {
public:
    string splitLoopedString(vector<string>& strs) {
        string res = "a", s;
        for(auto tmp:strs){
            string tmp2 = tmp;
            reverse(tmp2.begin(),tmp2.end());
            s+=(max(tmp,tmp2));
        }
        int ind = 0;
        for(int i = 0;i<strs.size();ind+=strs[i++].length()){
            string body = s.substr(ind+strs[i].length())+s.substr(0, ind);
            string tmp1 = strs[i];
            reverse(strs[i].begin(),strs[i].end());
            string tmp2 = strs[i];
            for(int k = 0;k<strs[i].length();k++){
                if(tmp1[k]>=res[0]) res = max(res, tmp1.substr(k)+body+tmp1.substr(0,k));
                if(tmp2[k]>=res[0]) res = max(res, tmp2.substr(k)+body+tmp2.substr(0,k));
            }
        }
        return res;
    }
};