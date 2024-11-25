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
