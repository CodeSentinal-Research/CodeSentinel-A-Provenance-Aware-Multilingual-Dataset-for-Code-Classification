from collections import Counter

def count_anagram_occurrences(s: str, p: str) -> int:
    p_count = Counter(p)
    s_count = Counter(s[:len(p)])
    ans = 1 if s_count == p_count else 0
    p_len = len(p)

    for i in range(p_len, len(s)):
        s_count[s[i]] += 1
        s_count[s[i - p_len]] -= 1
        if s_count[s[i - p_len]] == 0:
            del s_count[s[i - p_len]]
        if s_count == p_count:
            ans += 1

    return ans

if __name__ == '__main__':
    s = input().strip()
    p = input().strip()
    print(count_anagram_occurrences(s, p))