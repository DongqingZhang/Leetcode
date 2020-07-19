class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        if(N<=10) return min(N,9);
        vector<int> digits;
        int n = N;
        while(n){
            digits.push_back(n%10);
            n/=10;
        }
        reverse(digits.begin(),digits.end());
        int i;
        for(i = 1;i<digits.size();i++){
            if(digits[i]<digits[i-1]) break;
        }
        if(i == digits.size()) return N;
        int back = i-1;
        while(back>=0 && digits[i-1] == digits[back]) back--;
        digits[back+1]--;
        int res = 0;
        for(int i=0;i<digits.size();i++){
            res*=10;
            if(i<=back+1) res+=digits[i];
            else res+=9;
        }
        return res;
    }
};