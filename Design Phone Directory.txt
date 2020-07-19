class PhoneDirectory {
public:
    vector<int> avail;
    vector<bool> used;
    int n, maxN;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0;i < maxNumbers;i++){
            avail.push_back(i);
            used.push_back(false);
        }
        n = maxNumbers;
        maxN = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(!n) return -1;
        int tmp = avail[--n];
        used[tmp] = true;
        return tmp;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if(number < 0 || number >= this->maxN) return false;
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(check(number)) return;
        used[number] = false;
        avail[n++] = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */