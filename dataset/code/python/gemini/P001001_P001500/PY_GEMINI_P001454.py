def count_distinct_substrings(s: str) -> int:
    seen = set()
    n = len(s)
    for i in range(n):
        for j in range(i + 1, n + 1):
            seen.add(s[i:j])
    return len(seen) + 1  # include empty string

if __name__ == '__main__':
    s = input().strip()
    print(count_distinct_substrings(s))