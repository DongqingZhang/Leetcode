class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(auto a:words) freq[a]++;
        auto comp = [&](const pair<string, int>& a,const pair<string, int>& b){
            if(a.second == b.second) return a.first<b.first;
            return a.second>b.second;
        };
        typedef priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> myq;
        myq q(comp);
        for(auto a:freq){
            q.emplace(a.first, a.second);
            if(q.size()>k) q.pop();
        }
        vector<string> res;
        while(!q.empty()){
            res.insert(res.begin(),q.top().first);
            q.pop();
        }
        return res;
    }
    
};