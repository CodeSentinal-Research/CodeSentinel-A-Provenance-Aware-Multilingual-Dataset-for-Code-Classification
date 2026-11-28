
class Solution:
    def checkCase(self, c: str) -> str:
        if c.isupper():
            return "Uppercase"
        elif c.islower():
            return "Lowercase"
        return "Not an alphabet"
