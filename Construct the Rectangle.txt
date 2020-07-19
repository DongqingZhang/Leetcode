class Solution {
public:
    vector<int> constructRectangle(int area) {
        if(area == 0) return {0,0};
        int w = sqrt(area);
        while(area%w) w--;
        return {area/w, w};
    }
};