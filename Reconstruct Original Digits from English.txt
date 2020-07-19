class Solution {
public:
    string originalDigits(string s) {
        int zcnt = 0, ocnt = 0, wcnt = 0, tcnt = 0,ucnt = 0,fcnt = 0, xcnt = 0, vcnt = 0, gcnt = 0,icnt = 0;
        vector<int> cnt(10,0);
        int len = s.length();
        for(int i = 0;i<len;i++){
            if(s[i] == 'z') zcnt++;
            if(s[i] == 'o') ocnt++;
            if(s[i] == 'w') wcnt++;
            if(s[i] == 't') tcnt++;
            if(s[i] == 'u') ucnt++;
            if(s[i] == 'f') fcnt++;
            if(s[i] == 'x') xcnt++;
            if(s[i] == 'v') vcnt++;
            if(s[i] == 'g') gcnt++;
            if(s[i] == 'i') icnt++;
        }
        cnt[0] = zcnt;
        cnt[2] = wcnt;
        cnt[4] = ucnt;
        cnt[6] = xcnt;
        cnt[8] = gcnt;
        cnt[1] = ocnt - cnt[0] - cnt[2] - cnt[4];
        cnt[3] = tcnt - cnt[2] - cnt[8];
        cnt[5] = fcnt - cnt[4];
        cnt[7] = vcnt - cnt[5];
        cnt[9] = icnt - cnt[8] - cnt[6] - cnt[5];
        string res;
        for(int i = 0;i<10;i++){
            res.append(cnt[i],'0'+i);
        }
        return res;
    }
};