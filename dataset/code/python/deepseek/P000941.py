Here is the Python code:

def pileGame(N, piles):
    if N == 1:
        return "First"

    total = sum(piles)
    sum_piles = [0]
    for pile in piles:
        sum_piles.append(sum_piles[-1] + pile)

    for i in range(N - 1, -1, -1):
        if sum_piles[i] + (total - sum_piles[i]) / (N - i) <= sum_piles[N - 1]:
            return "First"

    return "Second"


def main():
    N = int(input().strip())
    piles = list(map(int, input().strip().split()))
    print(pileGame(N, piles))


if __name__ == '__main__':
    main()

This Python solution uses the concept of prefix sums to simplify the problem. For each pile, we calculate the sum so far. For the first pile, we don't need to subtract the remaining piles' sums because the first player can only remove all the stones. The second player can only remove the smallest possible pile. If the first player can remove the piles in a way that the second player can't remove any pile, then the first player wins. Otherwise, the second player will always win if the first player can always remove the piles in a way that the second player can't remove any pile.

The main function reads the number of piles and the pile sizes from the input, and then calls the `pileGame` function to determine the winner.