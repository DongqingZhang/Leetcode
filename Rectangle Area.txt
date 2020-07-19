class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return (C-A)*(D-B)+(G-E)*(H-F) - calcLength(A,C,E,G)*calcLength(B,D,F,H);
    }
    int calcLength(int l1, int r1, int l2, int r2){
        if (r2<=l1||r1<=l2) return 0;
        if ((l2-l1)*(l2-r1)*(r2-l1)*(r2-r1) >= 0) return min(abs(r1-l1),abs(r2-l2));
        else{
            if (r2>r1) return r1-l2;
            else return r2-l1;
        }
    }
};