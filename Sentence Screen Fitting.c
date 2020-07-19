class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int start = 0;
        string s;
        for(int i = 0;i < sentence.size();i++) s += (sentence[i]+" ");
        int len = s.length();
        for(int i = 0;i < rows;i++){
            start += cols;
            if(s[start%len] == ' ') start++;
            else{
                while(start > 0 && s[(start-1)%len]!=' ') start--;
            }
        }
        return start/len;
    }
};