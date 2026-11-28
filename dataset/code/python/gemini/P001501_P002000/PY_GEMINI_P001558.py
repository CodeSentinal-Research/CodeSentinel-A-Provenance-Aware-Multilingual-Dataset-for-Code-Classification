from collections import defaultdict

def length_of_longest_substring_k_distinct(s: str, k: int) -> int:
    if k == 0:
        return 0
    count = defaultdict(int)
    l = max_len = 0

    for r, c in enumerate(s):
        count[c] += 1
        while len(count) > k:
            count[s[l]] -= 1
            if count[s[l]] == 0:
                del count[s[l]]
            l += 1
        max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    s = input().strip()
    k = int(input())
    print(length_of_longest_substring_k_distinct(s, k))