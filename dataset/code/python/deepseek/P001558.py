def longest_substring(S, K):
    n = len(S)
    longest = 1
    i = 0
    while i < n:
        distinct_chars = set()
        j = i
        while j < n and S[j] in distinct_chars:
            distinct_chars.add(S[j])
            j += 1
        if len(distinct_chars) <= K:
            longest = max(longest, j - i)
        i = j
    return longest

S = input()
K = int(input())

def main():
    print(longest_substring(S, K))

if __name__ == "__main__":
    main()