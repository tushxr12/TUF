class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        set<int> st;

        for (auto i : nums)
            st.insert(i);

        int index = 0;
        for (auto i : st)
        {
            nums[index] = i;
            index++;
        }
        return st.size();
    }
};