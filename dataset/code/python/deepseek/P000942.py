Here is the Python code for the problem:

def stoneGame(piles):
    def helper(piles, l, r):
        if l > r:
            return 0
        return max(piles[l] - helper(piles, l + 1, r), piles[r] - helper(piles, l, r - 1))

    return helper(piles, 0, len(piles) - 1) >= 0


def main():
    n = int(input("Enter the number of piles: "))
    piles = list(map(int, input("Enter the piles: ").split()))
    print(stoneGame(piles))


main()

In this code, the `stoneGame` function takes an array of stone piles as input and returns True if the first player can guarantee a win. The `helper` function is a helper function for `stoneGame`. It recursively calculates the maximum difference between the player's choice and the opponent's choice when the current pile is taken. If the first player can guarantee a win, the `helper` function will return a positive number. If not, it will return zero.

The `main` function is the entry point of the program. It prompts the user to enter the number of piles and the piles themselves. It then calls the `stoneGame` function with the input piles and prints the result.

Please note that this code assumes that the piles are represented as an array of integers, where each integer represents the number of stones in one pile.