class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int len = data.size();
        for(int i=0;i<len;i++){
            if(data[i]>=128){
                int cnt = 0;
                while(data[i] & 0x80){
                    cnt++;
                    data[i]<<=1;
                }
                if(cnt>4||cnt==1) return false;
                while(--cnt) if((data[++i]&0xc0)!=128) return false;
            }
        }
        return true;
    }
};