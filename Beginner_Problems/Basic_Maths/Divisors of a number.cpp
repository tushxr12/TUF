class Solution
{
public:
    vector<int> divisors(int n)
    {
        vector<int> divisorss;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                divisorss.push_back(i);
            }
        }
        return divisorss;
    }
};