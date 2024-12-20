//Brute Force
class Solution
{
    private:
       vector<int> computeZArray(string s)
       {
          int n = s.size();
          vector<int> Z(n,0);

          for(int i = 1;i < n;i++)
          {
              while(i + Z[i] < n && s[i + Z[i]] == s[Z[i]])
                Z[i]++;
          }
          return Z;
       }
    public:
       vector<int> search(string text , string pattern){
          string s = pattern + '$' + text;
          vector<int> Z = computeZArray(s);
          int n = text.size(), m = pattern.size();

          vector<int> ans;
          for(int i = m + 1;i < s.size();i++)
            if(Z[i] == m)
              ans.push_back(i - (m + 1));
          return ans;
     }
};
