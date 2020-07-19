class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>> letters(words.size(),vector<int>(26,0));
        if (words.size()<2) return 0;
        vector<int> mask(words.size(),0);
        for (int i = 0;i<words.size();i++)
            for (int j = 0; j < words[i].size(); j++)
                mask[i] |= (1<<words[i][j] - 'a');
        int flag;
        int maxProd = 0;
        for (int i = 0;i < words.size();i++)
            for (int j = 0; j < words.size(); j++)
                if (i!=j&&!(mask[i]&mask[j])&&maxProd < words[i].length()*words[j].length())
                    maxProd = words[i].length()*words[j].length();
        return maxProd;
    }
};