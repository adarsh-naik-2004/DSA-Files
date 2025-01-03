/*
Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

*/

class MinStack {
public:
vector<pair<int,int>> st;
    void push(int val) {
        if(st.empty()){
            pair<int,int> p;
            p.first=val;
            p.second=val;
            st.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first=val;
            p.second=min(val,st.back().second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st.back().first;
    }
    
    int getMin() {
        return st.back().second;

    }
};
