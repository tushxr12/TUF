//Recursion Approach
class Solution {
private:
    
    int f(int day,int last, vector<vector<int>> &matrix)
    {
        if(day == 0)
        {
            int maxi = 0;
            for(int task = 0; task <= 2;task++)
            {
                if(task != last)
                {
                    maxi = max(maxi, matrix[0][task]);
                }
            }
            return maxi;
        }

        int maxi = 0;

        for(int task = 0; task <= 2;task++)
        {
            if(task != last)
            {
                int points = matrix[day][task] + f(day - 1,task, matrix);
                maxi = max(maxi, points);
            }
        }
        return maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        return f(n - 1,3,matrix);
    }
};


//Memoization Approach
class Solution {
private:
    int f(int day,int last, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(day == 0)
        {
            int maxi = 0;
            for(int task = 0; task <= 2;task++)
            {
                if(task != last)
                {
                    maxi = max(maxi, matrix[0][task]);
                }
            }
            return maxi;
        }

        if(dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for(int task = 0; task <= 2;task++)
        {
            if(task != last)
            {
                int points = matrix[day][task] + f(day - 1,task, matrix,dp);
                maxi = max(maxi, points);
            }
        }
        return dp[day][last] = maxi;
    }
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1,3,matrix, dp);
    }
};
