class Solution
{
public:
    bool isPrime(int n)
    {
        int cnt = 0;
        if (n <= 1)
        {
            return false;
        }
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;
            }
        }

        return (cnt == 2);
    }
    int primeUptoN(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (isPrime(i))
            {
                ans++;
            }
        }
        return ans;
    }
};