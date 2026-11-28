Here is the Python code that solves the problem:

def split_into_max_unique_substrings(s):
    n = len(s)
    suffixes = [s[i:] for i in range(len(s))]
    suffixes.sort(key=len, reverse=True)

    dp = [1] * len(suffixes)
    for i in range(1, len(suffixes)):
        for j in range(i):
            if s[j:j+suffixes[i].index(suffixes[j])] == suffixes[j]:
                dp[i] = max(dp[i], dp[j] + 1)

    return dp[-1]


def main():
    s = input().strip()
    print(split_into_max_unique_substrings(s))


if __name__ == "__main__":
    main()

This code first splits the input string into all possible substrings, and sorts them by their length in descending order. It then uses dynamic programming to find the maximum length of a unique substring that can be made from these substrings.

In the main function, the input string is read, and the function `split_into_max_unique_substrings` is called with this string as argument, and the result is printed out.