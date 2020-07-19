class WordDistance {
public:
    unordered_map<string, vector<int>> map;
    WordDistance(vector<string>& words) {
        for(int i = 0;i < words.size();i++) map[words[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        int minLen = INT_MAX;
        for(int i = 0,j = 0;i < map[word1].size() && j < map[word2].size();){
            minLen = min(minLen, abs(map[word1][i] - map[word2][j]));
            if(minLen == 1) return minLen;
            if(map[word1][i] - map[word2][j] < 0) i++;
            else if(map[word1][i] - map[word2][j] > 0) j++;
        }
        return minLen;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");