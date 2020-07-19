class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = sqsum(slow);
            fast = sqsum(fast);
            fast = sqsum(fast);
        }while(slow!=fast);
        return fast == 1;
    }
    int sqsum(int n){
        int sum = 0;
        while(n){
            sum += (n%10)*(n%10);
            n/=10;
        }
        return sum;
    }
};