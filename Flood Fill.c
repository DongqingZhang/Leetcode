class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        queue<pair<int,int>> q;
        q.push({sr, sc});
        int row = image.size(), col = image[0].size(), intensity = image[sr][sc];
        while(!q.empty()){
            pair<int,int> val = q.front();
            image[val.first][val.second] = newColor;
            q.pop();
            if(val.first-1 >= 0 && image[val.first-1][val.second] == intensity) q.push({val.first-1,val.second});
            if(val.first+1 < row && image[val.first+1][val.second] == intensity) q.push({val.first+1,val.second});
            if(val.second-1 >= 0 && image[val.first][val.second-1] == intensity) q.push({val.first,val.second-1});
            if(val.second+1 < col && image[val.first][val.second+1] == intensity) q.push({val.first,val.second+1});
        }
        return image;
    }
};