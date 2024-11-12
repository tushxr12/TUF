class Solution {
private:
    long long int func(int ind, vector<int> &money, vector<int> &dp)
    {
        if(ind == 0)
            return money[0];
        
        if(ind < 0)
            return 0;

        if(dp[ind] != -1)
            return dp[ind];
        
        int pick = money[ind] + func(ind - 2, money, dp);
        int notPick = 0 + func(ind - 1, money, dp);
        return dp[ind] = max(pick, notPick);
    }
public:
    int houseRobber(vector<int>& money) {
        vector<int> temp1;
        vector<int> temp2;
        int n = money.size();
        if(n == 1)
            return money[0];
        for(int i = 0;i < n;i++)
        {
            if(i != 0)
                temp1.push_back(money[i]);
            if(i != n -1)
                temp2.push_back(money[i]);
        }

        vector<int> dp1(n, -1);
        long long int ans1 = func(temp1.size() - 1, temp1, dp1);

        vector<int> dp2(n, -1);
        long long int ans2 = func(temp2.size() - 1, temp2, dp2);

        return max(ans1, ans2);
    }
};
