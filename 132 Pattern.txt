class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int s3 = INT_MIN;
        for(int i = nums.size()-1;i>=0;i--){
            if(s3 > nums[i]) return true;
            else{
                while(!s.empty() && s.top()<nums[i]){
                    s3 = s.top();
                    s.pop();
                }
                s.push(nums[i]);
            }
        }
        return false;
    }
};