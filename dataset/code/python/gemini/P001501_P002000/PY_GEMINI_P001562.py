from collections import defaultdict

def longest_substring_k_distinct(s: str, k: int) -> int:
    count = defaultdict(int)
    l = max_len = -1
    left = 0

    for r, c in enumerate(s):
        count[c] += 1
        while len(count) > k:
            count[s[left]] -= 1
            if count[s[left]] == 0:
                del count[s[left]]
            left += 1
        if len(count) == k:
            max_len = max(max_len, r - left + 1)

    return max_len

if __name__ == '__main__':
    s = input().strip()
    k = int(input())
    print(longest_substring_k_distinct(s, k))