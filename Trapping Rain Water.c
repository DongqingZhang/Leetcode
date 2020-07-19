class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int area = 0;
        int l = 0, r = height.size()-1;
        int maxL = height[l], maxR = height[r];
        while(l<r){
            if(maxL<maxR){
                if (maxL<height[l]) maxL = height[l];
                else{
                    area+=maxL-height[l];
                    l++;
                }
            }
            else{
                if (maxR<height[r]) maxR = height[r];
                else{
                    area+=maxR-height[r];
                    r--;
                }
            }
        }
        return area;
    }
};