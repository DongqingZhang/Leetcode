#include <iostream>
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (len == 0) return 0;
        vector<int> stats(len+1,0);
        for (int i = 0;i<len;i++){
            if (citations[i]>len) stats[len]++;
            else stats[citations[i]]++;
        }
        int t = 0;
        for (int i = len;i>=0;i--){
            t += stats[i];
            if (t>=i) return i;
        }
        return 0;
    }
};