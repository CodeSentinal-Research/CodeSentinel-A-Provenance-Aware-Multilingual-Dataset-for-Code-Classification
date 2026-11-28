class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        if N == 1:
            return 0
        mid = 2 ** (N - 1).bit_length()
        if K <= mid:
            return self.kthGrammar(N - 1, K)
        else:
            return 1 ^ self.kthGrammar(N - 1, K - mid)