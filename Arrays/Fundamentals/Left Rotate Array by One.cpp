class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int firstElement = nums[0];
        for(int i = 1;i < nums.size();i++)
        {
            nums[i - 1] = nums[i];
        }
        nums[nums.size() - 1] = firstElement;
    }
};