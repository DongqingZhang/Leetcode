class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> map;
        int num = ppid.size();
        for(int i = 0;i < num;i++) map[ppid[i]].push_back(pid[i]);
        queue<int> q;
        q.push(kill);
        vector<int> res;
        res.push_back(kill);
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            if(map.find(tmp)==map.end()) continue;
            for(int i = 0;i < map[tmp].size();i++){
                res.push_back(map[tmp][i]);
                q.push(map[tmp][i]);
            }
        }
        return res;
    }
};