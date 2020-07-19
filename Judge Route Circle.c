class Solution {
public:
    bool judgeCircle(string moves) {
        int cnthori = 0,cntvert = 0;
        for(auto a:moves){
            switch(a){
                case 'U':
                    cnthori++;
                    break;
                case 'D':
                    cnthori--;
                    break;
                case 'L':
                    cntvert++;
                    break;
                case 'R':
                    cntvert--;
                    break;
            }
        }
        cout<<cnthori<<cntvert;
        return cnthori == 0 && cntvert == 0;
    }
};