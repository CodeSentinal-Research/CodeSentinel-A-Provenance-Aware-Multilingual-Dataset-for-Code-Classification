
class Solution:
    def isSpecial(self, c: str) -> bool:
        return not c.isalnum() and not c.isspace()
