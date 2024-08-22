class Solution
{
public:
    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[low];
        int i = low, j = high;

        while (i < j)
        {
            while (nums[i] <= pivot && i <= high - 1)
                i++;

            while (nums[j] > pivot && j >= low + 1)
                j--;

            if (i < j)
                swap(nums[i], nums[j]);
        }
        swap(nums[low], nums[j]);
        return j;
    }

    void qsort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pInd = partition(nums, low, high);
            qsort(nums, low, pInd - 1);
            qsort(nums, pInd + 1, high);
        }
    }

    vector<int> quickSort(vector<int> &nums)
    {
        qsort(nums, 0, nums.size() - 1);
        return nums;
    }
};
