class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<unordered_set<int>> taken(3,unordered_set<int>());
        helper(n, &count, 0, taken);
        return count;
    }
    void helper(int n, int* count, int row, vector<unordered_set<int>>& taken){
        if (row == n) (*count)++;
        for (int i = 0;i<n;i++){
            if (taken[0].find(i) != taken[0].end()) continue;
            if (taken[1].find(i+row) != taken[1].end()) continue;
            if (taken[2].find(i-row) != taken[2].end()) continue;
            taken[0].insert(i);
            taken[1].insert(i+row);
            taken[2].insert(i-row);
            helper(n, count, row+1, taken);
            taken[0].erase(i);
            taken[1].erase(i+row);
            taken[2].erase(i-row);
        }
    }
};