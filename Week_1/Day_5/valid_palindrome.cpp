#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int p1 = 0;
        int p2 = s.length() - 1;
        
        while (p1 < p2) {
            // Skip non-alphanumeric characters from the left
            if (!std::isalnum(s[p1])) {
                p1++;
                continue;
            }
            // Skip non-alphanumeric characters from the right
            if (!std::isalnum(s[p2])) {
                p2--;
                continue;
            }
            
            // Compare characters by converting them to lowercase on the fly
            if (std::tolower(s[p1]) != std::tolower(s[p2])) {
                return false;
            }
            
            // Move both pointers inward after a successful match
            p1++;
            p2--;
        }
        
        return true;
    }
};
