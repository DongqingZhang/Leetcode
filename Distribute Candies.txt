class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> res;
        for(int i = 0;i<candies.size();i++){
            if(res.find(candies[i]) == res.end()) res.emplace(candies[i]);
        }
        return min(res.size(),candies.size()/2);
    }
};