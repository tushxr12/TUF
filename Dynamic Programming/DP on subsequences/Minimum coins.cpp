//Recursion
class Solution{
	private:
	int f(int ind, int amount, vector<int> &coins)
	{	
		if(ind == 0)
		{
			if(amount % coins[0] == 0)
			{
				return (amount/coins[0]);
			}else
			{
				return -1;
			}
		}

		int notPick = f(ind - 1, amount, coins);
		int pick = INT_MAX;
		if(amount >= coins[ind]){
			pick = 1 + f(ind, amount - coins[ind], coins);
		}
		return min(pick, notPick);
	}
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
		return f(coins.size() - 1, amount, coins);
    }
};

//Memoization
class Solution{
	private:
	int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
	{	
		if(ind == 0)
		{
			if(amount % coins[0] == 0)
			{
				return (amount/coins[0]);
			}else
			{
				return -1;
			}
		}

		if(dp[ind][amount] != -1)
			return dp[ind][amount];

		int notPick = f(ind - 1, amount, coins, dp);
		int pick = INT_MAX;
		if(amount >= coins[ind]){
			pick = 1 + f(ind, amount - coins[ind], coins,dp);
		}
		return dp[ind][amount] = min(pick, notPick);
	}
	public:
	int MinimumCoins(vector<int>& coins, int amount) {
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(amount + 1,-1));
		return f(coins.size() - 1, amount, coins, dp);
    }
};

//Tabulation
class Solution{
	public:
	int MinimumCoins(vector<int>& coins, int amountt) {
		int n = coins.size();
		vector<vector<int>> dp(n, vector<int>(amountt + 1,0));

		for(int i = 0;i <= amountt;i++)
		{
			if(i%coins[0] == 0)
				dp[0][i] = (i/coins[0]);
			else
				dp[0][i] = 1e9;
		}

		for(int ind = 1;ind < n;ind++)
		{
			for(int amount = 0; amount <= amountt;amount++)
			{
				int notPick = dp[ind - 1][amount];
				int pick = INT_MAX;
				if(amount >= coins[ind]){
					pick = 1 + dp[ind][amount - coins[ind]];
				}
				dp[ind][amount] = min(pick, notPick);
			}
		}

		if(dp[n - 1][amountt] >= 1e9)
			return -1;
		return dp[n - 1][amountt];
    }
};
