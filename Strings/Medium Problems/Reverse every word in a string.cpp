class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size();
        int start=-1, end = -1;
        vector<string> words;
        string ans = "";
        while(i < n)
        {
            while(i < n && s[i] == ' ')
                i++;
            
            if(i >= n)
                break;

            start = i;

            while(i < n && s[i] != ' ')
                i++;

            end = i - 1;
            words.push_back(s.substr(start,end - start + 1));
        }
        for(int i = words.size() - 1;i >= 0;i--)
        {
            ans += words[i];
            if(i != 0)
                ans += ' ';
        }
        return ans;
    } 
};
