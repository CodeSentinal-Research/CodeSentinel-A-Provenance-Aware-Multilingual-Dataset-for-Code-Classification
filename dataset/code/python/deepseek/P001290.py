Here is the Python code:

def solve():
    A, B, C = map(int, input().split())
    print(max(max(A, B), C) + max(A, B, C) - min(A, B, C))

if __name__ == "__main__":
    solve()

This code reads three integers A, B, C from the standard input and calculates the maximum obtainable score. The maximum obtainable score is the maximum of the three piles, the sum of the three piles, and the minimum of the three piles subtracted by the maximum of the three piles.