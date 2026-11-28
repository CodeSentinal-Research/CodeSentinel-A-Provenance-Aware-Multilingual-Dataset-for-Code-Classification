
from typing import List, Tuple

class Solution:
    def getAllAscii(self) -> List[Tuple[int, str]]:
        """
        Print All ASCII Characters: get all ascii

        Returns:
            All printable ASCII characters with their values.
        """
        return [(i, chr(i)) for i in range(128)]
