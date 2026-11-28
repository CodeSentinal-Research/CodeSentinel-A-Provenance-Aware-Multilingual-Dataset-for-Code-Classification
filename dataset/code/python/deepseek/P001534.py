Here is the Python code for the problem:

def longest_substring(s):
    max_length = 0
    distinct_chars = ''

    start = 0
    for end in range(len(s)):
        if s[end] in distinct_chars:
            start = max(start, distinct_chars.index(s[end]))
        if len(distinct_chars) > 2:
            distinct_chars = distinct_chars[distinct_chars.index(s[start]) + 1:]
        distinct_chars += s[end]
        max_length = max(max_length, len(distinct_chars))

    return max_length


s = input()
print(longest_substring(s))

This code uses a sliding window approach to track the maximum length and the characters of the longest substring. It iterates through the string, updating the start index if a character is repeated, and updating the substring if more than two distinct characters are found. The maximum length is updated accordingly.