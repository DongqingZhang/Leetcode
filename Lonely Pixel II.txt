class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int m = picture.size();
        if(m == 0) return 0;
        int n = picture[0].size();
        if(n == 0) return 0;
        unordered_map<string, pair<int, int>> map;
        vector<int> cnt(n,0);
        for(int i = 0;i<m;i++){
            string s;
            int cnt2 = 0;
            for(int j = 0;j<n;j++){
                s.push_back(picture[i][j]);
                if(picture[i][j] == 'B'){
                    cnt[j]++;
                    cnt2++;
                }
            }
            map[s].first++;
            map[s].second=cnt2;
        }
        int res = 0;
        for(auto a:map){
            if(a.second.first == N && a.second.second == N){
                int B = 0;
                for(int i = 0;i<n;i++){
                    if(a.first[i] == 'B' && cnt[i]==N) B++;
                }
                res+=N*B;
            }
        }
        return res;
    }
};