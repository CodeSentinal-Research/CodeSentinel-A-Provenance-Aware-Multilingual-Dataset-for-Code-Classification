def maxVowels(S, K):
    vowels = set("aeiou")
    dp = [0] * (len(S) + 1)
    max_vowels, max_sum = 0, 0

    for i in range(1, len(S) + 1):
        dp[i] = dp[i - 1]
        if S[i - 1] in vowels:
            dp[i] += 1
        if dp[i] == K:
            max_vowels = max(max_vowels, dp[i])
            max_sum += dp[i]

    return max_sum

def main():
    S = input().strip()
    K = int(input().strip())
    print(maxVowels(S, K))

if __name__ == "__main__":
    main()