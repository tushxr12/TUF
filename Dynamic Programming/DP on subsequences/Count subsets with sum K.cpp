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
