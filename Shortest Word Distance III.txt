class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int ind1 = -1, ind2 = -1, minD = INT_MAX, len=words.size();
        if(word1.compare(word2) != 0){
            for(int i=0;i<len;i++){
                if (words[i].compare(word1)==0) ind1 = i;
                if (words[i].compare(word2)==0) ind2 = i;
                if (ind1!=-1&&ind2!=-1) minD = min(minD,abs(ind1-ind2));
            }
        }
        else{
            int flag = 0;
            for(int i=0;i<len;i++){
                if (words[i].compare(word1)==0){ind2 = ind1;ind1 = i;}
                if (ind1!=-1&&ind2!=-1) minD = min(minD,abs(ind1-ind2));
            }
        }
        
        return minD;
    }
};