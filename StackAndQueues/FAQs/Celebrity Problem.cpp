//Brute force
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

//Optimal
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        int top = 0, down = n - 1;

        while(top < down)
        {
            if(M[top][down] == 1)
            {
                top += 1;
            }
            else if(M[down][top] == 1)
            {
                down -= 1;
            }
            else
            {
                top += 1;
                down -= 1;
            }
        }

        if(top > down)
        {
            return -1;
        }

        for(int i = 0;i < n;i++)
        {
            if(i == top)
                continue;
            if(M[top][i] == 0 && M[i][top] == 1)
            {
                //Nothing to do
            }
            else
                return -1;
        }

        return top;
    }
};
