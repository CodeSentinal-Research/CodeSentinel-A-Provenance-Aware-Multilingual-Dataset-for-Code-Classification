def longest_substring_at_most_k_vowels(s: str, k: int) -> int:
    vowels = set("aeiouAEIOU")
    l = v_count = max_len = 0

    for r, c in enumerate(s):
        if c in vowels:
            v_count += 1
        while v_count > k:
            if s[l] in vowels:
                v_count -= 1
            l += 1
        max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    s = input().strip()
    k = int(input())
    print(longest_substring_at_most_k_vowels(s, k))