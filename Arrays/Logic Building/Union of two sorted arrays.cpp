class Solution
{
public:
    vector<int> unionArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> ans;
        int i = 0, j = 0;
        set<int> st;
        while (i < n1 && j < n2)
        {
            if (nums1[i] <= nums2[j])
                st.insert(nums1[i++]);
            else
                st.insert(nums2[j++]);
        }

        while (i < n1)
            st.insert(nums1[i++]);
        while (j < n2)
            st.insert(nums2[j++]);

        for (auto i : st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};