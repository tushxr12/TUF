class Solution
{
public:
    void pattern14(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            char c = 'A';
            for (int j = 1; j <= i; j++)
            {
                cout << c;
                c++;
            }
            cout << "\n";
        }
    }
};