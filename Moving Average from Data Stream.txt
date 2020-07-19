class MovingAverage {
public:
    /** Initialize your data structure here. */
    int count = 0;
    int max = 0;
    queue<int> q;
    int sum = 0;
    MovingAverage(int size) {
        max = size;
    }
    
    double next(int val) {
        q.push(val);
        sum+=val;
        if (count < max){
            count++;
            return (double)sum/(double)count;
        }
        else{
            sum -= q.front();
            q.pop();
            return (double)sum/(double)count;
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */