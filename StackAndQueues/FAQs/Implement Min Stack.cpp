
class MinStack {
private:
  stack<pair<int,int>> st;
public:
  MinStack() {
    
  }

  void push(int value) {
      if(st.empty())
      {
        st.push({value, value});
        return;
      }
      else
      {
        st.push({value, min(value, st.top().second)});
      }
  }

  void pop() {
      st.pop();
  }

  int top() {
    if(!st.empty())
      return st.top().first;
    else
      return -1;
  }

  int getMin() {
    return st.top().second;
  }
};
