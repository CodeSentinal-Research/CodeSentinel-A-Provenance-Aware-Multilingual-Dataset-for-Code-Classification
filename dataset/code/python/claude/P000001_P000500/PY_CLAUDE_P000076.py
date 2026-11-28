
import cmath
from typing import Tuple

class Solution:
    def findRoots(self, a: float, b: float, c: float) -> Tuple[complex, complex]:
        d = (b ** 2) - (4 * a * c)
        root1 = (-b - cmath.sqrt(d)) / (2 * a)
        root2 = (-b + cmath.sqrt(d)) / (2 * a)
        return root1, root2
