
from typing import List

class Solution:
    def hanoi(self, n: int, src: str = 'A', dest: str = 'C', aux: str = 'B') -> List[str]:
        moves = []
        self._solve(n, src, dest, aux, moves)
        return moves

    def _solve(self, n, src, dest, aux, moves):
        if n == 1:
            moves.append(f'Move disk 1 from {src} to {dest}')
            return
        self._solve(n - 1, src, aux, dest, moves)
        moves.append(f'Move disk {n} from {src} to {dest}')
        self._solve(n - 1, aux, dest, src, moves)
