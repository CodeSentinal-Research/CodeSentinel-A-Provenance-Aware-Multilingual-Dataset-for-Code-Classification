class Solution:
    def removeDuplicates(self, s: str) -> str:
        seen = set()
        res = []
        for c in s:
            if c not in seen:
                seen.add(c)
                res.append(c)
        return "".join(res)