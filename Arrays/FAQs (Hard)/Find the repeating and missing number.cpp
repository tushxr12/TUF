// Brute
class Solution
{
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums)
    {
        int n = nums.size();
        int rep = -1, missing = -1;
        for (int i = 1; i <= n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == i)
                    cnt++;
            }

            if (cnt == 2)
                rep = i;
            else if (cnt == 0)
                missing = i;
            if (rep != -1 && missing != -1)
                break;
        }
        return {rep, missing};
    }
};

// Better
class Solution
{
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums)
    {
        int n = nums.size();
        int rep = -1, missing = -1;
        int hash[n + 1] = {0};

        for (int i = 0; i < n; i++)
        {
            hash[nums[i]]++;
        }

        // nums = [3, 5, 4, 1, 1]
        // hash = [2, 0, 1, 1, 1]
        //  cout<<"HASH::";
        //  for(int i = 0;i <= maxi;i++)
        //      cout<<hash[i]<<" ";
        //  cout<<"\n";

        for (int i = 1; i <= n; i++)
        {
            if (hash[i] == 0)
                missing = i;
            else if (hash[i] == 2)
                rep = i;
        }

        return {rep, missing};
    }
};

// Optimal
class Solution
{
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums)
    {
        long long n = nums.size();
        long long sn = (n * (n + 1)) / 2;
        long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
        long long s = 0, s2 = 0;

        for (int i = 0; i < n; i++)
        {
            s += nums[i];
            s2 += (long long)nums[i] * (long long)nums[i];
        }
        long long val1 = s - sn;
        long long val2 = s2 - s2n;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
};