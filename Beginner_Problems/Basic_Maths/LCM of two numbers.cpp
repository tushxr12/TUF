class Solution
{
public:
    int LCM(int n1, int n2)
    {
        int maxi = max(n1, n2);

        int i = 1;
        while (1)
        {
            int mul = maxi * i;
            if (mul % n1 == 0 && mul % n2 == 0)
            {
                return mul;
            }
            i++;
        }
        return maxi;
    }
};