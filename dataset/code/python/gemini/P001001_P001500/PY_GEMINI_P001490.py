class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        groups = []
        cur_len = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cur_len += 1
            else:
                groups.append(cur_len)
                cur_len = 1
        groups.append(cur_len)

        return sum(min(groups[i], groups[i + 1]) for i in range(len(groups) - 1))