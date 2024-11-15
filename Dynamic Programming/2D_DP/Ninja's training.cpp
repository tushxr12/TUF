class Solution {
private:
    //Recursion Approach
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
