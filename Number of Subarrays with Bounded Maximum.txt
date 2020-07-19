class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int len = A.size(), j = 0, res = 0, cnt = 0;
        for(int i = 0;i<len;i++){
            if(A[i]>=L && A[i]<=R){
                cnt = i-j+1;
                res+=cnt;
            }
            else if(A[i]<L) res+=cnt;
            else{
                cnt = 0;
                j = i+1;
            }
        }
        return res;
    }
};