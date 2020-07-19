class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> digit;
        int prod[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        for (int i = 1;i <= n;i++) digit.push_back(i);
        int cnt = n-1;
        while (cnt>=0){
            int curD = (k-1)/prod[cnt]+1;
            res.push_back(digit[curD-1]+48);
            k = (k-1)%prod[cnt]+1;
            cnt--;
            digit.erase(digit.begin()+curD-1);
        }
        return res;
    }
};