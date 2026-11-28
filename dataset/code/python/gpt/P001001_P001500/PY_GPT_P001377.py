# problem title : Isomorphic Strings
# Solve the stated task using standard input and standard output.
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return [s.find(c) for c in s] == [t.find(c) for c in t]
