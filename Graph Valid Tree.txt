class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjList(n,vector<int>());
        for(auto a:edges){
            adjList[a.first].push_back(a.second);
            adjList[a.second].push_back(a.first);
        }
        vector<int> visited(n,0);
        queue<pair<int,int>> q;
        if(hasCycle(-1,0,adjList,visited,q)) return false;
        for(int i=0;i<visited.size();i++){
            if (!visited[i]) return false;
        }
        return true;
    }
    bool hasCycle(int pre, int cur, vector<vector<int>>& adjList, vector<int>& visited, queue<pair<int,int>>& q){
        q.push({pre,cur});
        while(!q.empty()){
            pair<int,int> tmp = q.front();
            q.pop();
            if (visited[tmp.second]) return true;
            visited[tmp.second] = 1;
            for(int i:adjList[tmp.second]){
                if (i!=tmp.first) q.push({tmp.second,i});
            }
        }
        return false;
    }
};