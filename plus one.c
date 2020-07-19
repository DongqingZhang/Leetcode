class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int resDig;
        vector<int> res;
        int l1 = digits.size();
        for (int i = 1;i <= l1;i++){
            resDig = digits[l1 - i] + carry;
            if (resDig > 9)
                carry = 1;
            else
                carry = 0;
            res.push_back(resDig%10);
        }
        if (carry == 1)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};