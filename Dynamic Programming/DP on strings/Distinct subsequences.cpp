//Recursion
class Solution{
  private:
	int f(int i,int j, string s1, string s2)
	{
		if(j < 0) return 1;
		if(i < 0) return 0;
		if(s1[i] == s2[j])
		{
			return (f(i - 1,j - 1,s1,s2) + f(i - 1,j,s1,s2));
		}
		else
		{
			return f(i - 1,j,s1,s2);
		}
	}
  public:	
	int distinctSubsequences(string s, string t){
		int n = s.size(), m = t.size();
		return f(n - 1,m - 1,s,t);
	}
};
