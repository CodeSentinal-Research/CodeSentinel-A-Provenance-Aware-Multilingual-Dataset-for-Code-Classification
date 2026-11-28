
from typing import Dict
from collections import Counter

class Solution:
    def countChars(self, s: str) -> Dict[str, int]:
        return dict(Counter(s))
