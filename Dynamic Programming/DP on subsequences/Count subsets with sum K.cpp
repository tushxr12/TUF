//Recursion
class Solution{
	int modulo = 1e9+7;
	private:
	int f(int ind,int k, vector<int> &arr)
	{
		if(k == 0)
			return 1;
		if(ind == 0)
			return (arr[ind] == k);
		
		int notPick = f(ind - 1,k,arr);
		int pick = 0;
		if(k >= arr[ind])
			pick = f(ind - 1,k - arr[ind],arr);
		return (pick + notPick)%modulo;
	}
	public:
	int perfectSum(vector<int>&arr, int K){
		return f(arr.size() - 1,K,arr);
	}
};

//Memoization
class Solution{
	int modulo = 1e9+7;
	private:
	int f(int ind,int k, vector<int> &arr, vector<vector<int>> &dp)
	{
		if(k == 0)
			return 1;
		if(ind == 0)
			return (arr[ind] == k);
		if(dp[ind][k] != -1)
			return dp[ind][k];
		int notPick = f(ind - 1,k,arr,dp);
		int pick = 0;
		if(k >= arr[ind])
			pick = f(ind - 1,k - arr[ind],arr,dp);
		return (pick + notPick)%modulo;
	}
	public:
	int perfectSum(vector<int>&arr, int K){
		vector<vector<int>> dp(arr.size(), vector<int> (K + 1, -1));
		return f(arr.size() - 1,K,arr, dp);
	}
};

//Tabulation
class Solution{
	int modulo = 1e9+7;
	public:
	int perfectSum(vector<int>&arr, int K){
		vector<vector<int>> dp(arr.size(), vector<int> (K + 1, 0));
		for(int ind = 0; ind < arr.size();ind++)
		{
			dp[ind][0] = 1;
		}

		if(K >= arr[0])
			dp[0][arr[0]] = 1;

		for(int ind = 1;ind < arr.size();ind++)
		{
			for(int k = 1; k <= K;k++)
			{
				int notPick = dp[ind - 1][k];
				int pick = 0;
				if(k >= arr[ind])
					pick = dp[ind - 1][k - arr[ind]];
				dp[ind][k] = (pick + notPick)%modulo;
			}
		}
		return dp[arr.size() - 1][K];
	}
};

//Space optimization
class Solution{
	int modulo = 1e9+7;
	public:
	int perfectSum(vector<int>&arr, int K){
		vector<int> prev(K + 1, 0), curr(K + 1,0);
		prev[0] = 1;
		if(K >= arr[0])
			prev[arr[0]] = 1;
		curr[0] = 1;

		for(int ind = 1;ind < arr.size();ind++)
		{
			for(int k = 1; k <= K;k++)
			{
				int notPick = prev[k];
				int pick = 0;
				if(k >= arr[ind])
					pick = prev[k - arr[ind]];
				curr[k] = (pick + notPick)%modulo;
			}
			prev = curr;
		}
		return prev[K];
	}
};
