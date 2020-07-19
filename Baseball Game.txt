class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        int res = 0;
        for(auto a:ops){
            if(a[0] == 'C') s.pop();
            else if(a[0] == 'D'){
                int tmp = s.top();
                s.push(tmp*2);
            }
            else if(a[0] == '+'){
                int tmp1 = s.top();
                s.pop();
                int tmp2 = s.top();
                s.push(tmp1);
                s.push(tmp1+tmp2);
            }
            else s.push(stoi(a));
        }
        while(!s.empty()){
            res+=s.top();
            s.pop();
        }
        return res;
    }
};