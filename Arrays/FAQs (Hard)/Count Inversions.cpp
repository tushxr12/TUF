// Brute
class Solution
{
public:
    long long int numberOfInversions(vector<int> nums)
    {
        long long int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                    ans++;
            }
        }
        return ans;
    }
};

// Optimal(Using merge Sort)
class Solution
{
public:
    long long merge(vector<int> &arr, long long low, long long mid, long long high)
    {
        vector<long long> temp;
        long long left = low;
        long long right = mid + 1;

        long long cnt = 0;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {

                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (long long i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return cnt;
    }

    long long mergeSort(vector<int> &arr, long long low, long long high)
    {
        long long cnt = 0;
        if (low < high)
        {
            long long mid = low + (high - low) / 2;

            cnt += mergeSort(arr, low, mid);

            cnt += mergeSort(arr, mid + 1, high);

            cnt += merge(arr, low, mid, high);
        }
        return cnt;
    }

    long long int numberOfInversions(vector<int> nums)
    {
        long long n = nums.size();
        return mergeSort(nums, 0, n - 1);
    }
};