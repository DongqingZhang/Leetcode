class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int len = nums.size(), len0 = findNums.size();
        vector<int> res(len0, -1), res1(len, -1);
        stack<int> s;
        unordered_map<int,int> map;
        for(int i = 0;i < len;i++){
            while(!s.empty() && s.top() < nums[i]){
                map[s.top()] = nums[i];
                s.pop();
            }
            s.push(nums[i]);
        }
        for(int i = 0;i < len0;i++){
            if(map.find(findNums[i])!=map.end()) res[i] = map[findNums[i]];
        }
        return res;
    }
};