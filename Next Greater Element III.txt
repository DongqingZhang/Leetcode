class Solution {
public:
    int nextGreaterElement(int n) {
        if(n>-10 && n<10) return -1;
        vector<int> digs;
        long n1 = static_cast<long>(n);
        while(n1){
            digs.push_back(n1%10);
            n1/=10;
        }
        int i = 1;
        while(i < digs.size()){
            if(digs[i] < digs[i-1]) break;
            i++;
        }
        if(i == digs.size()) return -1;
        int j = 0;
        for(;j<i;j++){
            if(digs[j] > digs[i]){
                while(j<digs.size()-1 && digs[j]==digs[j+1]) j++;
                swap(digs[j], digs[i]);
                break;
            }
        }
        sort(digs.begin(),digs.begin()+i,std::greater<int>());
        long res = 0;
        for(int i = 0;i < digs.size();i++){
            res*=10;
            res+=digs[digs.size()-1-i];
        }
        return res>INT_MAX?-1:static_cast<int>(res);
    }
};