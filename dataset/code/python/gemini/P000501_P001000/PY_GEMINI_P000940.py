from typing import List

def misere_nim_winner(piles: List[int]) -> str:
    all_ones = all(x == 1 for x in piles)
    xor_sum = 0
    for x in piles:
        xor_sum ^= x
    if all_ones:
        return "First" if len(piles) % 2 == 0 else "Second"
    else:
        return "First" if xor_sum != 0 else "Second"

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        piles = list(map(int, input().split()))
        print(misere_nim_winner(piles))