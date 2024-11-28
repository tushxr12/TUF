//Recursion
class Solution {
  private:
  int f(int ind1, int ind2, string s1, string s2)
  {
    if(ind1 < 0 || ind2 < 0)
      return 0;

    //If match
    if(s1[ind1] == s2[ind2])
    {
      return 1 + f(ind1 - 1,ind2 - 1, s1, s2);
    }

    //If Not match
    return max(f(ind1 -1,ind2,s1 ,s2) , f(ind1, ind2 - 1, s1, s2));
  }
  public:
    int lcs(string str1, string str2) {
      return f(str1.size() - 1, str2.size() - 1, str1, str2);
    }
};
