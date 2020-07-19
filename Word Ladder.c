class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty()&&!tail.empty()) {
            if(head.size()<tail.size()){
                phead = &head;
                ptail = &tail;
            }
            else{
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> tmp;
            for(auto iter=phead->begin();iter!=phead->end();iter++){
                string word = *iter;
                for(int i=0;i<(int)word.length();i++){
                    char l = word[i];
                    for(int j=0;j<26;j++){
                        word[i] = 'a'+j;
                        if(ptail->find(word)!=ptail->end()) return dist;
                        if(wordDict.find(word)!=wordDict.end()){
                            tmp.insert(word);
                            wordDict.erase(word);
                        }
                    }
                    word[i] = l;
                }
            }
            dist++;
            swap(*phead, tmp);
        }
        return 0;
    }
};