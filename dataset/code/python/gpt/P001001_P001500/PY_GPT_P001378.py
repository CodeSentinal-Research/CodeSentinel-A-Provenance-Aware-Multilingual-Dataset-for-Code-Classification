# problem title : Word Pattern
# Solve the stated task using standard input and standard output.
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split()
        if len(pattern) != len(words):
            return False
        return len(set(zip(pattern, words))) == len(set(pattern)) == len(set(words))
