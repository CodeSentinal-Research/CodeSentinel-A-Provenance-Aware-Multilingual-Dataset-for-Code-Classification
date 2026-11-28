Here is the Python code for the problem:

def longest_substring_with_k_distinct_characters(s, k):
    max_len = 0
    dist_chars = {}
    start = 0
    for end in range(len(s)):
        if s[end] in dist_chars:
            dist_chars[s[end]] += 1
        else:
            dist_chars[s[end]] = 1

        while len(dist_chars) > k:
            dist_chars[s[start]] -= 1
            if dist_chars[s[start]] == 0:
                del dist_chars[s[start]]
            start += 1

        max_len = max(max_len, end - start + 1)

    return max_len if max_len > 0 else -1

if __name__ == "__main__":
    s = input()
    k = int(input())
    print(longest_substring_with_k_distinct_characters(s, k))

This code works by maintaining a sliding window with a start and end pointer. It keeps adding characters to the window until it contains exactly `k` distinct characters, then it tries to shrink the window by moving the start pointer. This ensures that the longest substring with exactly `k` distinct characters is found.

The `max_len` variable is used to keep track of the maximum length found. If no such substring exists, `max_len` is returned as `-1`.

The `dist_chars` dictionary is used to keep track of the number of distinct characters in the current window.