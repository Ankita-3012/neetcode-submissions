class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> st1 = st;
        int mini = INT_MAX;
        while(!st1.empty()){
            int num = st1.top();
            if(num<mini) mini = num;
            st1.pop();
        }
        return mini;
    }
};
