Here is the Python code for the problem:

def minWindow(s, t):
    from collections import Counter
    if not t or not s:
        return ''

    dict_t = Counter(t)
    required = len(dict_t)

    l, r = 0, 0
    formed = 0

    dict_s = {}

    min_length = float('inf')
    min_str = ''

    while r < len(s):
        dict_s[s[r]] = dict_s.get(s[r], 0) + 1

        if s[r] in dict_t and dict_s[s[r]] == dict_t[s[r]]:
            formed += 1

        while l <= r and formed == required:
            if r - l + 1 < min_length:
                min_length = r - l + 1
                min_str = s[l:r + 1]

            dict_s[s[l]] -= 1
            if s[l] in dict_t and dict_s[s[l]] < dict_t[s[l]]:
                formed -= 1

            l += 1

        r += 1

    return min_str

And here is the main function and input handling:

def main():
    t = input().strip()
    s = input().strip()
    print(minWindow(s, t))

if __name__ == "__main__":
    main()

Please note that this code works only for ASCII characters. If you have strings with Unicode characters, you need to use a different approach.