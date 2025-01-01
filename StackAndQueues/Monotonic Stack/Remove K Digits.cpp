class Solution {
public:
    string removeKdigits(string nums, int k) {
        string ans = "";
        stack<char> st;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            while(!st.empty() &&  k > 0 && (st.top() > nums[i]))
            {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }

        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }

        if(st.empty())
            return "0";
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        while(ans.size() != 0 && ans.back() == '0')
            ans.pop_back();
        
        if(ans.size() == 0)
            return "0";
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
