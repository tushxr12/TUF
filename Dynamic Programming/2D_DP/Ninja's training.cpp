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

//Tabulation Approach
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = max(matrix[0][1], matrix[0][2]);
        dp[0][1] = max(matrix[0][0], matrix[0][2]);
        dp[0][2] = max(matrix[0][0], matrix[0][1]);
        dp[0][3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

        for(int day = 1; day < n;day++)
        {
            for(int last = 0; last <= 3;last++)
            {
                dp[day][last] = 0;

                for(int task = 0; task <= 2;task++)
                {
                    if(task != last)
                    {
                        int point = matrix[day][task] + dp[day-1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }

        return dp[n-1][3];
    }
};

//Space Optimized Approach - Test
class Solution {
public:
    int ninjaTraining(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(4, 0);
        prev[0] = max(matrix[0][1], matrix[0][2]);
        prev[1] = max(matrix[0][0], matrix[0][2]);
        prev[2] = max(matrix[0][0], matrix[0][1]);
        prev[3] = max({matrix[0][0], matrix[0][1], matrix[0][2]});

        for(int day = 1; day < n;day++)
        {
            vector<int> temp(4,0);
            for(int last = 0; last <= 3;last++)
            {
                temp[last] = 0;

                for(int task = 0; task <= 2;task++)
                {
                    if(task != last)
                    {
                        int point = matrix[day][task] + prev[task];
                        temp[last] = max(temp[last], point);
                    }
                }
            }
            prev = temp;
        }

        return prev[3];
    }
};
