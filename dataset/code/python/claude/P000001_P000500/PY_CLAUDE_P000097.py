
class Solution:
    def isDuck(self, s: str) -> bool:
        s = s.lstrip('0')
        return '0' in s
