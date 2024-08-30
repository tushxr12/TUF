// Brute
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = 0, right = 0, index = 0;
        vector<int> merged(n + m);

        while (left < m && right < n)
        {
            if (nums1[left] <= nums2[right])
                merged[index++] = nums1[left++];
            else
                merged[index++] = nums2[right++];
        }

        while (left < m)
            merged[index++] = nums1[left++];

        while (right < n)
            merged[index++] = nums2[right++];

        for (int i = 0; i < (n + m); i++)
            nums1[i] = merged[i];
    }
};

// Optimal
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = m - 1, right = 0;

        while (left >= 0 && right <= n - 1)
        {
            if (nums1[left] > nums2[right])
                swap(nums1[left--], nums2[right++]);
            else
                break;
        }
        sort(nums1.begin() + 0, nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[i - m];
        }
    }
};