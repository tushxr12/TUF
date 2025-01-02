class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();

        vector<int> iKnow(n), knowMe(n);

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(M[i][j] == 1)
                {
                    knowMe[j]++;
                    iKnow[i]++;
                }
            }
        }

        int ans = -1;
        for(int i = 0;i < n;i++)
        {
            if(iKnow[i] == 0 && knowMe[i] == n - 1)
            {
                return i;
            }
        }
        return ans;
    }
};
