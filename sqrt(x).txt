class Solution {
public:
    int mySqrt(int x) {
        int a = 1;
        int b = min(x,46341);
        int temp = (a+b)/2;
        while(temp*temp!=x&&(b-a)>1){
            if (temp*temp < x) a = temp;
            else b = temp;
            temp = (a + b)/2;
        }
        return temp;
    }
};