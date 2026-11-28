from collections import defaultdict

def longest_substring_exactly_k(s: str, k: int) -> int:
    def at_most(limit: int) -> int:
        if limit == 0:
            return 0
        count = defaultdict(int)
        l = max_len = 0
        for r, c in enumerate(s):
            count[c] += 1
            while len(count) > limit:
                count[s[l]] -= 1
                if count[s[l]] == 0:
                    del count[s[l]]
                l += 1
            max_len = max(max_len, r - l + 1)
        return max_len

    count_all = defaultdict(int)
    l = max_len = 0
    for r, c in enumerate(s):
        count_all[c] += 1
        while len(count_all) > k:
            count_all[s[l]] -= 1
            if count_all[s[l]] == 0:
                del count_all[s[l]]
            l += 1
        if len(count_all) == k:
            max_len = max(max_len, r - l + 1)

    return max_len if max_len > 0 else -1

if __name__ == '__main__':
    s = input().strip()
    k = int(input())
    print(longest_substring_exactly_k(s, k))