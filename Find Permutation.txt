class Solution {
public:
    vector<int> findPermutation(string s) {
        int len = s.length();
        vector<int> res;
        int minv = 1, tmp = 1, inds = 0;
        while(1){
            tmp = minv;
            if(tmp > len+1) return res;
            while(inds<len && s[inds++] == 'D') tmp++;
            for(int i = 0;i<tmp-minv+1;i++) res.push_back(tmp-i);
            minv = tmp+1;
        }
        return res;
    }
};