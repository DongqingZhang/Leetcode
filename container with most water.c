class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxA = 0;
        int lh = 0, rh = height.size()-1;
        while(lh<rh){
            maxA = max(maxA, min(height[lh],height[rh])*(rh-lh));
            if (height[lh] < height[rh]) lh = lh+1;
            else rh = rh-1;
        }
        return maxA;
    }
};