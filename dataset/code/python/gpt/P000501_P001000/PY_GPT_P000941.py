# problem title : Standard Nim Game
# Solve the stated task using standard input and standard output.
from typing import List

def nim_winner(piles: List[int]) -> str:
    xor_sum = 0
    for x in piles:
        xor_sum ^= x
    return "First" if xor_sum != 0 else "Second"

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        piles = list(map(int, input().split()))
        print(nim_winner(piles))
