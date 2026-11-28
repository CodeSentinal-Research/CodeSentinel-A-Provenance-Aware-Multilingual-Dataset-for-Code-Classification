Here is the Python code for the problem:

def length_of_longest_substring(s):
    max_len = 0
    s_len = len(s)
    chars = [0] * 128
    start = 0
    for i in range(s_len):
        if chars[ord(s[i])] > 0:
            start = max(start, chars[ord(s[i])])
        chars[ord(s[i])] = i + 1
        max_len = max(max_len, i - start + 1)
    return max_len

def main():
    s = input("Enter a string: ")
    print(length_of_longest_substring(s))

main()

In the code above, we are maintaining a sliding window approach. We use a variable `start` to record the last occurrence position of a character in the current substring. We also use a `chars` array to record the last occurrence of each character. As we iterate through the string, if we find a repeated character, we know the current window should not include that character, so we move our `start` to the position after the last occurrence of that character.