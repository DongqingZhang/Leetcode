/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==nullptr) return nullptr;
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        q.push(node);
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> map;
        map[node] = copy;
        while(!q.empty()){
            UndirectedGraphNode *cur = q.front();
            q.pop();
            for(auto neigh:cur->neighbors){
                if(map.find(neigh)==map.end()){
                    UndirectedGraphNode *mycopy = new UndirectedGraphNode(neigh->label);
                    map[neigh] = mycopy;
                    q.push(neigh);
                }
                map[cur]->neighbors.push_back(map[neigh]);
            }
        }
        return copy;
    }
};