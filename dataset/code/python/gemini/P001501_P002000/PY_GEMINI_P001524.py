class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def getMax(c_target: str) -> int:
            l = cnt = 0
            for r, c in enumerate(answerKey):
                if c != c_target:
                    cnt += 1
                if cnt > k:
                    if answerKey[l] != c_target:
                        cnt -= 1
                    l += 1
            return len(answerKey) - l

        return max(getMax('T'), getMax('F'))