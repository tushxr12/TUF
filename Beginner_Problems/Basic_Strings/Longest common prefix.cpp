class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {
        sort(str.begin(), str.end());

        string x = str[0];
        string y = str[str.size() - 1];

        string ans = "";

        for (int i = 0; i < max(x.size(), y.size()); i++)
        {
            if (x[i] != y[i])
            {
                return ans;
            }
            else
            {
                ans += x[i];
            }
        }

        return ans;
    }
};