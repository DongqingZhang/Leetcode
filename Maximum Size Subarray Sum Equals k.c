class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int len = 0, sum = 0;
        unordered_map<int, int> myMap;
        for (int i = 0;i<nums.size();i++){
            sum += nums[i];
            if (sum == k) len = i+1;
            else if(myMap.find(sum-k)!=myMap.end()) len = max(len,i-myMap[sum-k]);
            if (myMap.find(sum)==myMap.end()) myMap[sum] = i;
        }
        return len;
    }
};