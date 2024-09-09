class Solution
{
private:
    void pattern2(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
                cout << "*";
            cout << "\n";
        }
    }

    void pattern5(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n - i + 1; j++)
                cout << "*";
            cout << "\n";
        }
    }

public:
    void pattern10(int n)
    {
        pattern2(n);
        pattern5(n - 1);
    }
};