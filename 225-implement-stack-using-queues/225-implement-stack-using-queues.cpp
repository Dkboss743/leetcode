class MyStack {
public:
    queue<int> ans;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = ans.size();
        ans.push(x);
        for(int i=0; i<n; i++){
            ans.push(ans.front());
            ans.pop();
        }
    }
    
    int pop() {
      int val = ans.front();
        ans.pop();
        return val;
    }
    
    int top() {
        return ans.front();
    }
    
    bool empty() {
        return ans.empty();
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