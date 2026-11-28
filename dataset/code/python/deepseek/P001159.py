Here is a Python code for the above problem. The main idea is to use dynamic programming. We will create a dp array with the size of n+1 to store the decoding counts. dp[i] will store the decoding counts for the string till index i. We will start from the end of the string and update the dp[i] based on the dp[i+1] and dp[i+2] (if the string till index i and i+1 are valid).

def decodeWays(string):
    n = len(string)
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 0 if string[0] == '0' else 1

    for i in range(1, n):
        if string[i] == '0':
            dp[i + 1] = 0
        else:
            dp[i + 1] = dp[i]
        if string[i - 1:i + 1] >= '10' and string[i - 1:i + 1] <= '26':
            dp[i + 1] += dp[i - 1]

    return dp[n]


def main():
    string = input().strip()
    print(decodeWays(string))


if __name__ == '__main__':
    main()

This code will read a numeric string from the input and print the number of possible decodings. The input string is read using Python's built-in `input` function. The `strip` function is used to remove the leading and trailing whitespace from the string.

This code will handle the input strings of length up to 10^5, as required in the constraints.