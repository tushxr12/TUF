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
