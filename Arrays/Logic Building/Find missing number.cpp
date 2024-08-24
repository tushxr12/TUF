class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int hash[n + 1] = {0};
        for(auto i : nums)
            hash[i] = 1;

        for(int i = 0;i <= n;i++)
            if(hash[i] == 0)
                return i;
        
        return -1;
    }
};