class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        if (n < 2) {
            return s;
        }

        int bestStart = 0;
        int bestLength = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }

            int currentLength = right - left - 1;

            if (currentLength > bestLength) {
                bestLength = currentLength;
                bestStart = left + 1;
            }
        };

        for (int center = 0; center < n; center++) {
            expand(center, center);       // odd length palindrome
            expand(center, center + 1);   // even length palindrome
        }

        return s.substr(bestStart, bestLength);
    }
};