class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while(V--) addDrop(heights, K);
        return heights;
    }
    void addDrop(vector<int>& heights, int ind){
        int i = ind;
        while(i > 0){
            if(heights[i]<heights[i-1]) break;
            if(heights[i]>heights[i-1]){
                addDrop(heights,i-1);
                return;
            }
            i--;
        }
        i = ind;
        while(i < heights.size()-1){
            if(heights[i]<heights[i+1]) break;
            if(heights[i]>heights[i+1]){
                addDrop(heights,i+1);
                return;
            }
            i++;
        }
        heights[ind]++;
    }
};