class Solution
{
public:
    int countDigit(int n)
    {
        string nToString = to_string(n);
        return nToString.size();
    }
};