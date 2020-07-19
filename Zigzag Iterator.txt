class ZigzagIterator {
public:
    vector<int> v;
    int cnt = 0;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int cnt1=0, cnt2=0;
        while(cnt1<v1.size()||cnt2<v2.size()){
            if (cnt1 < v1.size()) v.push_back(v1[cnt1++]);
            if (cnt2 < v2.size()) v.push_back(v2[cnt2++]);
        }
    }

    int next() {
        return v[cnt++];
    }

    bool hasNext() {
        return cnt<v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */