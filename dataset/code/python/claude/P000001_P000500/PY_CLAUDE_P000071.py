
class Solution:
    def typeOfTriangle(self, a: float, b: float, c: float) -> str:
        if not (a + b > c and a + c > b and b + c > a):
            return "Invalid"
        if a == b == c:
            return "Equilateral"
        elif a == b or b == c or a == c:
            return "Isosceles"
        return "Scalene"
