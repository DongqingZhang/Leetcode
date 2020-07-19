class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, maxv = 0;
        for(int i = 0;i<arr.size();i++){
            maxv = max(maxv,arr[i]);
            if(maxv == i) res++;
        }
        return res;
    }
};