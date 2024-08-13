class Solution
{
public:
    int GCD(int n1, int n2)
    {
        int i = 1, ans = 1;
        while (i <= min(n1, n2))
        {
            if (n1 % i == 0 && n2 % i == 0)
            {
                ans = i;
            }
            i++;
        }
        return ans;
    }
};