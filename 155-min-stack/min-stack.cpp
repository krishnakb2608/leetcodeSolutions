class MinStack {
private:
    stack<int>st;
    stack<int>minStack;

public:
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minStack.empty() || value<=minStack.top()){
            minStack.push(value);
        }
    }
    
    void pop() {
        if(st.empty())return;
        if(minStack.top()==st.top()){
            minStack.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */