class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> myMap;
        vector<int> cumuMap(nums.size()+1,0);
        for (auto &i:nums){
            ++cumuMap[++myMap[i]];
        }
        int minFreq = nums.size();
        for (;minFreq > 0 && cumuMap[minFreq] < k; minFreq--);
        vector<int> res;
        int count = 0;
        for (auto &pair:myMap){
            if (pair.second > minFreq && count < k){
                res.push_back(pair.first);
                count++;
            }
        }
        for (auto &pair:myMap){
            if (pair.second == minFreq && count < k){
                res.push_back(pair.first);
                count++;
            }
        }
        return res;
    }
};