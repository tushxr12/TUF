class Solution {
public:
    int reverseNumber(int n) {
        string nToString = to_string(n);
        reverse(nToString.begin(), nToString.end());
        int ans = stoi(nToString);
        return ans;
    }
};