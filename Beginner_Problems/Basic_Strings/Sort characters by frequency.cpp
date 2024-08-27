class Solution
{
public:
    vector<char> frequencySort(string &s)
    {
        vector<pair<int, int>> v(26, {0, 0});
        for (int i = 0; i < 26; i++)
        {
            v[i].second = 26 - i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a'].first++;
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        vector<char> ans;
        for (int i = 0; i < 26; i++)
        {
            if (v[i].first > 0)
            {
                ans.push_back('a' + (26 - v[i].second));
            }
        }
        return ans;
    }
};
