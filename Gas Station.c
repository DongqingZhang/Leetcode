class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size(), tank = 0, total = 0, start = 0;
        for(int i=0;i<len;i++){
            if((tank=tank+gas[i]-cost[i])<0){
                start = i+1;
                total+=tank;
                tank = 0;
            }
        }
        total+=tank;
        return total>=0?start:-1;
    }
};