class Solution
{
public:
    bool rotateString(string &s, string &goal)
    {
        // your code goes here
        if (s == goal)
            return true;

        s += s; // abcdeabcde
        return s.find(goal) != string::npos;
    }
};