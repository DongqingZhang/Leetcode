class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqs(26,0);
        for(auto a:tasks) freqs[a-'A']++;
        sort(freqs.begin(), freqs.end());
        int i = 25;
        while(i>=0 && freqs[i] == freqs[25]) i--;
        int len = tasks.size();
        return max(len, (freqs[25]-1)*(n+1)+25-i);
    }
};