class Solution
{
public:
    bool isPrime(int n)
    {
        // your code goes here
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                ans++;
        }
        return (ans == 2);
    }
};