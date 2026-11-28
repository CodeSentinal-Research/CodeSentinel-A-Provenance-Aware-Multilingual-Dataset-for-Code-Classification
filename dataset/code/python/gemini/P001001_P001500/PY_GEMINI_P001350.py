class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        res = []

        def backtrack(cur: str):
            if len(cur) == n:
                res.append(cur)
                return
            for c in "abc":
                if not cur or cur[-1] != c:
                    backtrack(cur + c)

        backtrack("")
        return res[k - 1] if k <= len(res) else ""