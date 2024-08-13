class Solution {
public:
    bool isArmstrong(int n) {
        int orig = n;

        int sumOfDigits = 0;
        while(n)
        {
            int lastDigit = n%10;
            sumOfDigits += pow(lastDigit,3);
            n /= 10;
        }

        return (sumOfDigits == orig);
    }
};