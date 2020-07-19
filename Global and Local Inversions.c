class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int len = A.size();
        for(int i = 0;i<len;i++) if(abs(A[i]-i)>1) return false;
        return true;
    }
};