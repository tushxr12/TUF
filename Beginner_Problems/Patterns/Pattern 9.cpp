class Solution {
    private:
    void pattern7(int n)
    {
        for(int i = 1;i <= n;i++)
        {
            {
                for(int j = 1;j <= n- i;j++)
                cout<<" ";
            
                for(int j = 1;j <= 2*i - 1;j++)
                    cout<<"*";

                for(int j = 1;j <= n - i;j++)
                    cout<<" ";
            }
            cout<<"\n";
        }
    }
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

    
public:
    void pattern9(int n) {
        pattern7(n);
        pattern8(n);
    }
};