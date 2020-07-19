class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int m = pairs.size();
        sort(pairs.begin(), pairs.end(), comp);
        int sum = 0, curind = 0, i = -1;
        while(++i < m){
            sum++;
            curind = i;
            while(i+1<m && pairs[i+1][0]<=pairs[curind][1]) i++;
        }
        return sum;
    }
};