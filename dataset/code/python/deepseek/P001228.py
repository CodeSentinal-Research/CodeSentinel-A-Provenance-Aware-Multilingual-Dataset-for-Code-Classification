Here is the Python code:

import sys

def input_data():
    first_line = sys.stdin.readline().strip().split(' ')

    if len(first_line) != 3 or not all(map(lambda x: x.isdigit(), first_line)) or not (1 <= int(first_line[0]) <= 50) or not (2 <= int(first_line[1]) <= 30) or not (1 <= int(first_line[2]) <= 1000):
        print('Invalid input!')
        exit(0)

    return [int(x) for x in first_line]

def dice_throw(d, f, s):
    dp = [[0] * (s + 1) for _ in range(d + 1)]

    for i in range(d + 1):
        dp[i][0] = 1

    for i in range(1, d + 1):
        for j in range(1, s + 1):
            for k in range(1, f + 1):
                dp[i][j] += dp[i - 1][j - k]

    print(dp[d][s])

def main():
    D, F, S = input_data()
    dice_throw(D, F, S)

if __name__ == "__main__":
    main()

This program reads the input data, checks if it is valid, and then performs the dice throw problem. It uses a dynamic programming approach to solve the problem. The dp table dp[i][j] represents the number of ways to obtain a sum j using i dice. The base case is dp[i][0] = 1 for i in [1, D] and dp[i][j] += dp[i - 1][j - k] for k in [1, f] and j in [1, s]. The final answer is dp[D][S].