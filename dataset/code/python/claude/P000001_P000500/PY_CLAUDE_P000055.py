
class Solution:
    def printAlphabetZA(self) -> str:
        """
        Print Alphabet from Z to A: print alphabet z a

        Returns:
            Z Y X ... A
        """
        return "".join(chr(i) for i in range(ord('Z'), ord('A') - 1, -1))
