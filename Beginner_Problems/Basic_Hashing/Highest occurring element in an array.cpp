class Solution {
public:
    int mostFrequentElement(vector<int>& nums) {
        int ans = 0, mc= 0;
        map<int,int> mpp;

        for(auto i : nums)
        {
            mpp[i]++;
        }
        for(auto i : mpp)
        {
            if(i.second > mc)
            {
                mc = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};