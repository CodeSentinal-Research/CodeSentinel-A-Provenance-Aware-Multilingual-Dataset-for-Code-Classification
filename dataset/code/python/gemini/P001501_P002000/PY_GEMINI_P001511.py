class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def getMax(target: str) -> int:
            l = 0
            cnt = 0
            for r, c in enumerate(answerKey):
                if c != target:
                    cnt += 1
                if cnt > k:
                    if answerKey[l] != target:
                        cnt -= 1
                    l += 1
            return len(answerKey) - l

        return max(getMax('T'), getMax('F'))