// Brute
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int cnt = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > 2 * nums[j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// Optimal (Using merge sort)
class Solution
{
public:
    void merge(vector<int> &nums, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid)
            temp.push_back(nums[left++]);

        while (right <= high)
            temp.push_back(nums[right++]);

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high)
    {
        int right = mid + 1, cnt = 0;
        for (int i = low; i <= mid; i++)
        {
            while (right <= high && nums[i] > 2 * nums[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int sortt(vector<int> &nums, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;

        cnt += sortt(nums, low, mid);
        cnt += sortt(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

    int reversePairs(vector<int> &nums)
    {
        return sortt(nums, 0, nums.size() - 1);
    }
};