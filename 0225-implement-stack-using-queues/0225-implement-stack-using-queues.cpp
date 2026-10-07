class MyStack {
public:

    // Queue used to implement the stack
    queue<int> q;

    MyStack() {
    }

    // Push an element onto the stack
    void push(int x) {

        // Add the new element to the queue
        q.push(x);

        // Move all previous elements behind x
        int n = q.size();

        for (int i = 0; i < n - 1; i++) {

            q.push(q.front());
            q.pop();
        }
    }

    // Remove and return the top element
    int pop() {

        int ans = q.front();
        q.pop();

        return ans;
    }

    // Return the top element
    int top() {

        return q.front();
    }

    // Check whether the stack is empty
    bool empty() {

        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */