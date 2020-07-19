class Queue {
public:
    stack<int> input, output;
    // Push element x to the back of queue.
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (output.empty()){
            while(!input.empty()){
                int tmp = input.top();
                input.pop();
                output.push(tmp);
            }
        }
        output.pop();
    }

    // Get the front element.
    int peek(void) {
        if (output.empty()){
            while(!input.empty()){
                int tmp = input.top();
                input.pop();
                output.push(tmp);
            }
        }
        return output.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return input.empty()&&output.empty();
    }
};