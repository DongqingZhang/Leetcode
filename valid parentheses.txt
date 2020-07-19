class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) return true;
        vector<char> myStack;
        myStack.push_back(s[0]);
        char cur;
        for (int i = 1;i < s.length();i++){
            if (s[i] == '('||s[i] == '['||s[i] == '{'){
                myStack.push_back(s[i]);
                continue;
            }
            else{
                cur = myStack.back();
                if (s[i] == ')'&&cur!='(') return false;
                if (s[i] == '}'&&cur!='{') return false;
                if (s[i] == ']'&&cur!='[') return false;
                myStack.pop_back();
            }
        }
        if (myStack.size() == 0) return true;
        else return false;
    }
};