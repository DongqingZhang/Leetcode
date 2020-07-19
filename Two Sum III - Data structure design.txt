class TwoSum {
public:
    unordered_map<int,int> map;
    // Add the number to an internal data structure.
	void add(int number) {
        map[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(auto a:this->map){
	        int tmp = value - a.first;
	        if((tmp == a.first && a.second >= 2) || (tmp!=a.first && map.find(tmp)!=map.end())){
	            return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);