class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int i = 1, len = temperatures.size();
        stack<int> s;
        s.push(0);
        vector<int> res(len,0);
        for(int i = 1;i<len;i++){
            while(!s.empty() && temperatures[i] > temperatures[s.top()]){
                int ind = s.top();
                res[ind] = i-ind;
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};