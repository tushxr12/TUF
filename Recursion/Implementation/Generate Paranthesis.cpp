// Optimal
class Solution
{
public:
    void solve(int open, int close, int n, string s, vector<string> &ans)
    {
        if (open == close && (open + close) == 2 * n)
        {
            ans.push_back(s);
            return;
        }

        if (open < n)
            solve(open + 1, close, n, s + '(', ans);

        if (open > close)
            solve(open, close + 1, n, s + ')', ans);
    }

    vector<string> generateParenthesis(int n)
    {
        // your code goes here
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};