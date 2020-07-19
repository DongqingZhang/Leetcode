class Solution {
public:
    int lengthLongestPath(string input) {
        int len = input.length(), ln = 1, maxLen = 0, cnt = 0;
        bool isFile = false;
        vector<int> level(200,0);
        for (int i=0;i<len;i++){
            while(i<len&&input[i]=='\t'){
                i++;ln++;
            }
            while(i<len&&input[i]!='\n'){
                if (input[i]=='.') isFile = true;
                cnt++;
                i++;
            }
            if (isFile) maxLen = max(maxLen,level[ln-1]+cnt);
            else level[ln]=level[ln-1]+cnt+1;
            ln = 1;
            isFile = false;
            cnt = 0;
        }
        return maxLen;
    }
};