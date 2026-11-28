
from typing import List, Dict
from collections import Counter

class Solution:
    def frequency(self, arr: List[int]) -> Dict[int, int]:
        return dict(Counter(arr))
