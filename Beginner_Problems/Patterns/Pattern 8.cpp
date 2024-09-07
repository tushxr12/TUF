class Solution
{
public:
    void pattern8(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
                cout << " ";
            for (int j = 0; j < (2 * n) - (2 * i + 1); j++)
            {
                cout << "*";
            }
            for (int j = 0; j < i; j++)
                cout << " ";
            cout << "\n";
        }
    }
};
/*
    ********* //5 -> 9
    _*******_ //4 -> 7
    __*****__ //3 -> 5
    ___***___ //2 -> 3
    ____*____ //1 -> 1
*/