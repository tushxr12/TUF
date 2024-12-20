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
