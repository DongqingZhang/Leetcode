class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, len = bits.size();
        if(len == 1) return true;
        while(i<len-1){
            if(!bits[i]) i++;
            else i+=2;
        }
        return i == len-1;
    }
};