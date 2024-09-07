class Solution
{
public:
    void solve(int ind, string s, string digits, string combos[], vector<string> &ans)
    {
        if (ind == digits.size())
        {
            ans.push_back(s);
            return;
        }

        // Convert digit from string to int
        int number = digits[ind] - '0';

        // Recursion Loop
        for (int i = 0; i < combos[number].size(); i++)
        {
            solve(ind + 1, s + combos[number][i], digits, combos, ans);
        }
    }

    vector<string> letterCombinations(string digits)
    {
        // your code goes here
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        solve(0, s, digits, combos, ans);
        return ans;
    }
};