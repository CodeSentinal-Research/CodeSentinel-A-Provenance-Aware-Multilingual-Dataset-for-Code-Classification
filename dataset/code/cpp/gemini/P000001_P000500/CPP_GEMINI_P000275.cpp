#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int write = 0, read = 0, n = chars.size();

        while (read < n) {
            char ch = chars[read];
            int count = 0;
            while (read < n && chars[read] == ch) {
                read++;
                count++;
            }

            chars[write++] = ch;

            if (count > 1) {
                for (char c : std::to_string(count)) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
};