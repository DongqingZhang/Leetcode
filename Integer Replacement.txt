class Solution {
public:
    int integerReplacement(int n) {
        if(n == INT_MAX) return integerReplacement(n/2+1)+2; 
        if(n == 1) return 0;
        if(n%2 == 0) return integerReplacement(n/2)+1;
        else return min(integerReplacement(n+1),integerReplacement(n-1))+1;
        int cnt = 0;
        while(n != 1){
            if(n%2 == 0){
                cnt++;
                n/=2;
            }
            else{
                cnt++;
                if((n+1)%4==0) n++;
                else n--;
            }
        }
        return cnt;
    }
};