class Solution:
    def maxPower(self, s: str) -> int:
        """Calculates modular exponentiation (base^exp % mod) efficiently."""
        max_run = 1
        cur_run = 1
        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                cur_run += 1
                max_run = max(max_run, cur_run)
            else:
                cur_run = 1
        return max_run