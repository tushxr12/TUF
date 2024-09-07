class Solution
{
public:
    bool isPalindrome(string s, int left, int right)
    {
        while (left < right)
        {
            if (s[left++] != s[right--])
            {
                return false;
            }
        }
        return true;
    }

    void solve(int ind, vector<vector<string>> &ans, vector<string> &ds, string s)
    {
        if (ind == s.size())
        {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                string substr = s.substr(ind, i - ind + 1);
                ds.push_back(substr);
                solve(i + 1, ans, ds, s);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        // your code goes here
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, ans, ds, s);
        return ans;
    }
};