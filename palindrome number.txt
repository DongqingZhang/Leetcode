class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int head,tail;
        int base = 1;
        while(x/base>=10){
            base*=10;
        }
        while(x){
            head = x/base;
            tail = x%10;
            if (head!=tail)
                return false;
            x -= head*base;
            x /=10;
            base/=100;
        }
        return true;
    }
};