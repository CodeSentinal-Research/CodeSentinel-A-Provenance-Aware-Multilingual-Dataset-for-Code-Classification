def longest_palindrome(s):
    if not s:
        return ""

    def expand_around_center(s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1

    start, end = 0, 0
    for i in range(len(s)):
        length1 = expand_around_center(s, i, i)
        length2 = expand_around_center(s, i, i + 1)
        size = max(length1, length2)
        if size > end - start:
            start = i - (size - 1) // 2
            end = i + size // 2
    return s[start:end + 1]


s = input("Enter a string: ")
print("Longest Palindromic Substring: ", longest_palindrome(s))