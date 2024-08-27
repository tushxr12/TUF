class Solution
{
public:
    vector<char> reverseString(vector<char> &s)
    {
        // your code goes here
        reverse(s.begin(), s.end());

        return s;
    }
};