Here's the Python code:

def is_anagram(s, t):
    return sorted(s) == sorted(t)

s = input().strip()
t = input().strip()
print('YES' if is_anagram(s, t) else 'NO')

This code reads two strings from the input and sorts them. If the sorted strings are equal, they are anagrams.