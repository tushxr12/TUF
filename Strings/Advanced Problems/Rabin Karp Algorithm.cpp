//Brute Force
class Solution
{
    public:
    vector <int> search(string pat, string text)
    {
        vector<int> ans;
        for(int i = 0;i <= text.size() - pat.size();i++)
        {
            bool fl = true;
            for(int j = 0;j < pat.size();j++)
            {
                if(pat[j] != text[i + j])
                {
                    fl = false;
                    break;
                }
            }
            if(fl)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Optimal
class Solution
{
    public:
    vector <int> search(string pat, string text)
    {
        vector<int> ans;
        int n = pat.size();
        int m = text.size();

        int p = 7, mod = 101;

        int pRight = 1, pLeft = 1;
        int hashPat = 0, hashText = 0;

        for(int i = 0;i < n;i++)
        {
            hashPat += ((pat[i] - 'a' + 1) * pRight)%mod;
            hashText += ((text[i] - 'a' + 1) * pRight)%mod;
            pRight = (pRight*p)%mod;
        }

        for(int i = 0;i <= m - n;i++)
        {
            // cout<<"Inside for loop\n";
            // cout<<"Hash pattern : "<<hashPat<<" , Hash Text  : "<<hashText<<"\n";
            if(hashPat == hashText)
            {
                // cout<<"inside if 1 : ";
                if(text.substr(i,n) == pat)
                {
                    // cout<<"Inside if 2 : ";
                    ans.push_back(i);
                }
                    
            }

            hashText = (hashText - ((text[i] - 'a' + 1)*pLeft)%mod + mod)%mod;
            hashText = (hashText + ((text[i + n] - 'a' + 1)*pRight)%mod) % mod;
            hashPat = (hashPat*p)%mod;

            pLeft = (pLeft*p)%mod;
            pRight = (pRight*p)%mod;
        }
        // cout<<"Printing ans : "<<ans.size();
        return ans;
    }
};
