class CustomStack {
public:
    vector<int>stk, inc;
    int top;
    CustomStack(int maxSize) 
    {
        stk.resize(maxSize);
        inc.resize(maxSize);
        top = -1;
    }
    
    void push(int x) 
    {
        if(top != stk.size()-1)
        {
            ++top;
            stk[top] = x;
        }
    }
    
    int pop() 
    {
        if(top == -1) return -1;
        int res = stk[top] + inc[top];
        if(top != 0)
        {
            inc[top-1] += inc[top];
        }
        inc[top] = 0;
        --top;
        return res;
    }
    
    void increment(int k, int val) 
    {
        int minInc = min(k-1, top);
        if(minInc >= 0)
        {
            inc[minInc] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */