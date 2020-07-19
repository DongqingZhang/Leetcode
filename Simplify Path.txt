class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> stk;
        string res;
        string item;
        while(getline(ss,item,'/')){
            if(item==""||item==".") continue;
            if(item==".."&&!stk.empty()) stk.pop_back();
            if(item!="..") stk.push_back(item);
        }
        for(auto a:stk) res += "/"+a;
        return res.empty()?"/":res;
    }
};