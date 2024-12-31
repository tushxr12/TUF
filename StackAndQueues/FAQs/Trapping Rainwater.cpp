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

//Optimzal
class Solution
{
public:
    int trap(vector<int> &height){
        int lMax = 0, rMax = 0, total = 0, left = 0 ,right = height.size() - 1;

        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(lMax > height[left])
                {
                    total += (lMax - height[left]);
                }
                else
                {
                    lMax = height[left];
                }
                left += 1;
            }
            else
            {
                if(rMax > height[right])
                {
                    total += (rMax - height[right]);
                }
                else
                {
                    rMax = height[right];
                }
                right -= 1;
            }
        }
        return total;
    }
};
