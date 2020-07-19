class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<bool> tmp(9,false);
        int cnt = 0;
        helper(&cnt, m, n, 0, tmp, -1000);
        return cnt;
    }
    void helper(int* cnt, int m, int n, int k, vector<bool>& tmp, int prev){
        if (k>n) return;
        if (k>=m) ++*cnt;
        for (int i = 1;i<10;i++){
            if (tmp[i-1]) continue;
            if (((i == 7&&prev == 1)||(i == 1&&prev == 7))&&tmp[3]==false) continue;
            if (((i == 9&&prev == 3)||(i == 3&&prev == 9))&&tmp[5]==false) continue;
            if ((prev+i == 4&&tmp[1]==false)||(prev+i == 16&&tmp[7]==false)||(prev+i == 10&&tmp[4]==false)) continue;
            tmp[i-1] = true;
            helper(cnt, m, n, k+1, tmp, i);
            tmp[i-1] = false;
        }
    }
};