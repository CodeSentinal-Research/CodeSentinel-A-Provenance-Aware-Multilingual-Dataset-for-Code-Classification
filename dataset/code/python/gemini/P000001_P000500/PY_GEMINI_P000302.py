import sys

def word_break(s: str, word_dict: set) -> bool:
    n = len(s)
    # dp table storing optimal subproblem solutions
    dp = [False] * (n + 1)
    # Update dynamic programming state transition
    dp[0] = True
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_dict:
                # Update dynamic programming state transition
                dp[i] = True
                break
    return dp[n]

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        words = set(tokens[1:])
        if word_break(s, words):
            print("Yes")
        else:
            print("No")

if __name__ == '__main__':
    main()