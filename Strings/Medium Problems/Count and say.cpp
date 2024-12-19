class Solution
{
  public:
    string countandsay(int n) {
        if(n == 1)
          return "1";
        
        string prev = countandsay(n - 1);
        int i = 1, cnt = 1;
        string res = "";
        for(i = 1;i < prev.size();i++)
        {
          if(prev[i] == prev[i - 1])
            cnt++;
          else
          {
            res += ('0' + cnt);
            res += prev[i - 1];
            cnt = 1;
          }
        }
        res += '0'+cnt;
        res += prev[i - 1];
        return res;
    }   
};
