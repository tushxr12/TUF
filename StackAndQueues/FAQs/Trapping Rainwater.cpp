class Solution
{
public:
    int trap(vector<int> &height){
        int n = height.size();
        vector<int> prefMax(n), suffixMax(n);

        prefMax[0] = height[0];
        for(int i = 1;i < n;i++)
            prefMax[i] = max(prefMax[i - 1], height[i]);

        suffixMax[n - 1] = height[n - 1];
        for(int i = n - 2;i >= 0;i--)
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        

        int ans = 0;
        for(int i = 0;i < n;i++)
        {
            int leftMax = suffixMax[i], rightMax = prefMax[i];
            if(height[i] < leftMax && height[i] < rightMax)
                ans += (min(leftMax, rightMax) - height[i]);
        }
        return ans;
    }
};
