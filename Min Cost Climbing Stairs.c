class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.insert(cost.begin(),0);
        int len = cost.size();
        vector<int> allcost(len+1,0);
        for(int i = 1;i < len;i++){
            allcost[i+1] = min(allcost[i] + cost[i+1], allcost[i-1] + cost[i]);
        }
        return allcost[len];
    }
};