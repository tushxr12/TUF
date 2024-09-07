class Solution
{
public:
    int addDigits(int num)
    {
        // your code goes here
        if (num < 10)
        {
            return num;
        }

        // Recursive case: sum the digits and continue
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};