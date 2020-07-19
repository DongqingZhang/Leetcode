class Solution {
public:
    bool checkRecord(string s) {
        int len = s.length(), cntA = 0, cntL = 0;
        bool l = false;
        for(int i = 0;i<len;i++){
            if(s[i] == 'A') cntA++;
            if(s[i] == 'L'){
                cntL++;
                if(cntL == 3) l = true;
            }
            else cntL = 0;
            if(cntA >= 2 || l) return false;
        }
        return true;
    }
};