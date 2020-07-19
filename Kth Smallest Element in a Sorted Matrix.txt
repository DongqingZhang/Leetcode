class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int res;
        int n = matrix.size();
        if (n == 0||k == 0) return 0;
        auto cmp = [&matrix](pair<int,int>& a,pair<int,int>& b){
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(cmp)> q(cmp);
        q.push({0,0});
        while(k--&&q.size()){
            auto tmp = q.top();q.pop();
            res = matrix[tmp.first][tmp.second];
            if (tmp.first+1<n) q.push({tmp.first+1,tmp.second});
            if (tmp.first == 0 && tmp.second+1<n) q.push({tmp.first,tmp.second+1});
        }
        return res;
    }
};