class Solution {
public:
    int countRev (string s) {
        int n = s.size();
        if(n%2)
            return -1;
        int open = 0, close = 0;

        for(int i = 0;i < n;i++)
        {
            if(s[i] == '(')
            {
                open++;
            }
            else
            {
                if(open)
                {
                    open--;
                }
                else
                {
                    close++;
                }
            }
        }

        return (open/2 + open%2) + (close/2 + close%2);
    }
};
