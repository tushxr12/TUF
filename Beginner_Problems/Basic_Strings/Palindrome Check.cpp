class Solution
{
public:
    bool palindromeCheck(string &s)
    {
        // your code goes here
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }
        return true;
    }
};