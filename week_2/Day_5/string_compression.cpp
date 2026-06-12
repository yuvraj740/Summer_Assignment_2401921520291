class Solution {
public:
    int compress(vector<char>& chars) {
        int pos = 0;
        int start = 0;
        int n = chars.size();

        while (start < n) {
            int end = start;

            while (end < n && chars[end] == chars[start]) {
                ++end;
            }

            chars[pos++] = chars[start];

            int len = end - start;

            if (len > 1) {
                string cnt = to_string(len);

                for (char ch : cnt) {
                    chars[pos++] = ch;
                }
            }

            start = end;
        }

        return pos;
    }
};