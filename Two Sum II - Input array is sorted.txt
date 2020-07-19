class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int i = 0, j = len-1;
        vector<int> res;
        while(i < j){
            while(i < j && numbers[i]+numbers[j] > target) j--;
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            while(i < j && numbers[i]+numbers[j] < target) i++;
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
        }
        return {};
    }
};