class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty()) {
            return "";
        }

        string prefix = "";

        for (int pos = 0; pos < strs[0].size(); pos++) {

            char currentChar = strs[0][pos];

            for (int i = 1; i < strs.size(); i++) {

                if (pos >= strs[i].size() || strs[i][pos] != currentChar) {
                    return prefix;
                }
            }

            prefix += currentChar;
        } 

        return prefix;
    }
};
