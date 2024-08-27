class Solution
{
public:
    bool isomorphicString(string s, string t)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);

        for (auto i : s)
        {
            v1[i - 'a']++;
        }

        for (auto i : t)
        {
            v2[i - 'a']++;
        }

        sort(v1.begin(), v1.end(), greater<int>());
        sort(v2.begin(), v2.end(), greater<int>());

        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                return false;
                break;
            }
        }
        return true;
    }
};