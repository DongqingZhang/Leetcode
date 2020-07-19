class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1) return false;
        int sum = 1, i;
        for(i = 2;i<=sqrt(num);i++){
            if(num%i == 0){
                sum += i;
                sum += (num/i);
            }
        }
        if(i*i == num) sum-=i;
        cout<<sum;
        return sum == num;
    }
};