class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> a0 = helper(a);
        pair<int, int> b0 = helper(b);
        return to_string(a0.first*b0.first - a0.second*b0.second)+'+'+to_string(a0.first*b0.second + a0.second*b0.first)+'i';
    }
    pair<int,int> helper(string a){
        for(int i = 0;i<a.length();i++){
            if(a[i] == '+') return {stoi(a.substr(0,i)),stoi(a.substr(i+1,a.length()-i-2))};
        }
    }
};