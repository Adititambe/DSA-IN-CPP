class MyQueue {
public:

    // First stack Second stack
    stack<int> s1;
    
    stack<int> s2;

    MyQueue() {
    }

    // Add  element to the queue
    void push(int x) {
        s1.push(x);
    }

    // Remove and return the front element
    int pop() {

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {

            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        // Get the front element
        int ans = s2.top();

        // Remove the front element
        s2.pop();

        return ans;
    }

    // Return the front element
    int peek() {

        // If s2 is empty, transfer all elements from s1 to s2
        if (s2.empty()) {

            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // Check whether the queue is empty
    bool empty() {

        // Queue is empty only when both stacks are empty
        return s1.empty() && s2.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */