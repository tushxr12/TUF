class Solution
{
public:
    int sumHighestAndLowestFrequency(vector<int> &nums)
    {
        int ans = 0;
        int lf = INT_MAX, hf = INT_MIN;
        map<int, int> mpp;
        for (auto i : nums)
            mpp[i]++;

        for (auto i : mpp)
        {
            if (i.second < lf)
            {
                lf = i.second;
            }

            if (i.second > hf)
            {
                hf = i.second;
            }
        }
        ans = hf + lf;
        return ans;
    }
};
