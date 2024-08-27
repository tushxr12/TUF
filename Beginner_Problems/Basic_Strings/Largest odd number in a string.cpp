class Solution{	
public:		
    string largeOddNum(string& s){
        //your code goes here
        int n = s.size();
        string ans = "";
        int ind = -1;
        //"00112334556"
        for(int i = n - 1;i >= 0;i--)
        {
            if((s[i]-'0')%2)
            {
                ind = i;
                break;
            }
        }
        if(ind == -1)
            return ans;
        
        int nonZeroIndex = -1;

        for(int i = 0;i < ind;i++)
        {
            if(s[i]-'0' != 0)
            {
                nonZeroIndex = i;
                break;
            }
        }

        for(int i = nonZeroIndex; i <= ind;i++)
        {
            ans += s[i];
        }
        return ans;
    }
};