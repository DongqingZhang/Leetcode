class Solution {
public:
    string parseTernary(string expression) {
        stack<char> s;
        int len = expression.length();
        for(int i = len-1;i>=0;i--){
            if(!s.empty() && s.top() == '?'){
                s.pop();
                char c1 = s.top();
                s.pop();
                s.pop();
                char c2 = s.top();
                s.pop();
                if(expression[i] == 'T') s.push(c1);
                else s.push(c2);
            }else s.push(expression[i]);
        }
        char c = s.top();
        return &c;
    }
};