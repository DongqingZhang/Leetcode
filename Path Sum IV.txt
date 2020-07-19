class Solution {
public:
    int pathSum(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();i++) map[nums[i]/10] = nums[i]%10;
        return trav(map, 1, 1, 0);
    }
    int trav(unordered_map<int,int>& map, int depth, int pos, int sum){
        if(map.find(depth*10+pos)==map.end()) return 0;
        sum += map[depth*10+pos];
        if(map.find((depth+1)*10+pos*2) == map.end() && map.find((depth+1)*10+pos*2-1) == map.end()) return sum;
        return trav(map, depth+1, pos*2-1, sum)+trav(map, depth+1, pos*2, sum);
    }
};