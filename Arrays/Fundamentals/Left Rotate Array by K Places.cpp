class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        while(k--)
        {
            int firstElement = nums[0];
            for(int i = 1;i < n;i++)
            {
                nums[i - 1] = nums[i];
            }
            nums[n - 1] = firstElement;
        }
    }
};