Here is the Python code for the problem:

def longest_substring_without_repeating_characters(s):
    if not s:
        return 0

    left = 0
    used_chars = [False] * 256

    max_len = 0
    current_len = 0

    for i in range(len(s)):
        if used_chars[ord(s[i])]:
            max_len = max(max_len, current_len)
            while s[left] != s[i]:
                used_chars[ord(s[left])] = False
                left += 1
            left += 1
        else:
            used_chars[ord(s[i])] = True
            current_len += 1

    max_len = max(max_len, current_len)

    return max_len


def main():
    s = input()
    print(longest_substring_without_repeating_characters(s))


if __name__ == "__main__":
    main()

In this code, we use a sliding window approach. We initialize two pointers, `left` and `right`, to the start of the string. We maintain a `used_chars` list to keep track of the characters that have been seen. For each character in the string, we first check if it's already in the current substring. If it is, we slide the window to the right until the repeated character is removed. Otherwise, we increase the current length and update the maximum length if necessary. We finally return the maximum length.