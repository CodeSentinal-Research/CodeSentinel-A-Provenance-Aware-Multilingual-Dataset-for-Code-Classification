Here is the Python code for the problem:

def check_same_chars(s1, s2):
    s1_freq = {}
    s2_freq = {}

    for char in s1:
        if char in s1_freq:
            s1_freq[char] += 1
        else:
            s1_freq[char] = 1

    for char in s2:
        if char in s2_freq:
            s2_freq[char] += 1
        else:
            s2_freq[char] = 1

    for char in s1:
        if s1_freq[char] != s2_freq[char]:
            return "No"

    return "Yes"

s1 = input()
s2 = input()

print(check_same_chars(s1, s2))

This program reads two strings as input, checks if they contain the same characters with the same frequencies, and prints "Yes" or "No" accordingly.