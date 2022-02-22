class MinStack {
    stack<int>stk1;
    stack<int>min_stk;
public:
    MinStack() 
    {
        min_stk.push(INT_MAX);
    }
    
    void push(int val) 
    {
        stk1.push(val);
        min_stk.push(min(min_stk.top(), val));
    }
    
    void pop() 
    {
        stk1.pop();
        min_stk.pop();
    }
    
    int top() 
    {
        return stk1.top();
    }
    
    int getMin() 
    {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */