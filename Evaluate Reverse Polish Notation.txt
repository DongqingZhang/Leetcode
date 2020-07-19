class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int len = tokens.size();
        if(len == 0) return 0;
        for(int i=0;i<len;i++){
            bool charType = !tokens[i].compare("+")||!tokens[i].compare("-")||!tokens[i].compare("*")||!tokens[i].compare("/");
            if(charType){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                if(tokens[i][0]=='+') stk.push(a+b);
                if(tokens[i][0]=='-') stk.push(a-b);
                if(tokens[i][0]=='*') stk.push(a*b);
                if(tokens[i][0]=='/') stk.push(a/b);
            }
            else stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
};