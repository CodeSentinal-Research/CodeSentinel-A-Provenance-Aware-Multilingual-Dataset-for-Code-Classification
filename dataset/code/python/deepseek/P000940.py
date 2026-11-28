Here is a Python solution for the problem:

def misere_nim(N, piles):
    xor = 0
    for pile in piles:
        xor ^= pile
    if xor:
        print("First")
    else:
        print("Second")

N = int(input())
piles = list(map(int, input().split()))
misere_nim(N, piles)

In this code, we calculate the XOR of all piles. If the XOR is not zero, it means that there is a pile with an even number of stones, so the first player wins. Otherwise, the second player wins.

The input handling part is straightforward: we first read N (the number of piles), and then we read the piles (space separated). We then pass these values to the misere_nim function.