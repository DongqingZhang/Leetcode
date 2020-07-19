class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int d0 = mandist({0,0},target);
        int mindist = INT_MAX;
        for(auto a:ghosts) if(mandist(a,target) <= d0) return false;
        return true;
    }
    int mandist(vector<int> s, vector<int> d){
        return abs(s[0]-d[0])+abs(s[1]-d[1]);
    }
};