class Solution:
    def minWindow(self, s1: str, s2: str) -> str:
        m, n = len(s1), len(s2)
        min_len = m + 1
        start_idx = -1
        i = j = 0

        while i < m:
            if s1[i] == s2[j]:
                j += 1
                if j == n:
                    end = i
                    j -= 1
                    while j >= 0:
                        if s1[i] == s2[j]:
                            j -= 1
                        i -= 1
                    i += 1
                    j = 0
                    if end - i + 1 < min_len:
                        min_len = end - i + 1
                        start_idx = i
            i += 1

        return s1[start_idx:start_idx + min_len] if start_idx != -1 else ""