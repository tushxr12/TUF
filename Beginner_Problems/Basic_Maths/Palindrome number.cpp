class Solution
{
public:
    bool isPalindrome(int n)
    {
        string nToString = to_string(n);
        int i = 0, j = nToString.size() - 1;
        while (i < j)
        {
            if (nToString[i++] != nToString[j--])
            {
                return false;
            }
        }
        return true;
    }
};