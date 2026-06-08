class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26, 0);

        for (char ch : magazine) {
            letters[ch - 'a']++;
        }

        for (char ch : ransomNote) {
            if (letters[ch - 'a'] == 0) {
                return false;
            }

            letters[ch - 'a']--;
        }

        return true;
    }
};