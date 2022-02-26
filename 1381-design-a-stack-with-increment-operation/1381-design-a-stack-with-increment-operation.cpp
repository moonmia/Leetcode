class CustomStack {
private:
    stack<int>stk;
    vector<int>inc{vector<int>(1000, 0)};
    int size_max =-1;
    
public:
    CustomStack(int maxSize) 
    {
        size_max = maxSize;
    }
    
    void push(int x) 
    {
        if(stk.size() < size_max)
        {
            stk.push(x);
        }
    }
    
    int pop() 
    {
        if(stk.empty()) return -1;
        else
        {
            int n = stk.size();
            int val = stk.top() + inc[n-1];
            stk.pop();
            if(n >=2)
            {
                inc[n-2] += inc[n-1];
            }
            inc[n-1] =0;
            return val;
        }
    }
    
    void increment(int k, int val) 
    {
        int n = min(k, int(stk.size()));
        if(n ==0) return;
        else inc[n-1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */