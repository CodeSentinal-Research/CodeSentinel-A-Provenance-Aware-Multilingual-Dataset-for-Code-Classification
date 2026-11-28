
class Solution:
    def printAlphabetAZ(self) -> str:
        """
        Print Alphabet from A to Z: print alphabet a z

        Returns:
            A B C ... Z
        """
        return "".join(chr(i) for i in range(ord('A'), ord('Z') + 1))
