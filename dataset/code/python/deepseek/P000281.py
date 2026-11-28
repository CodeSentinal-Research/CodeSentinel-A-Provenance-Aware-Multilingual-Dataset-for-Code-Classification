Sure, here's the Python code for finding the smallest window in S that contains all characters of T using a sliding window approach.

def min_window(s, t):
    if not t or not s:
        return ''

    from collections import Counter
    dict_t = Counter(t)

    l, r = 0, 0
    formed = 0
    window_counts = dict()

    min_length = float('inf')
    min_string = ''

    while r < len(s):
        character = s[r]
        window_counts[character] = window_counts.get(character, 0) + 1

        if character in dict_t and window_counts[character] == dict_t[character]:
            formed += 1

        while l <= r and formed == len(dict_t):
            character = s[l]
            if window_counts[character] == dict_t[character]:
                formed -= 1

            window_counts[character] -= 1

            min_length = min(min_length, r - l + 1)
            l += 1

        r += 1

    return min_string


def main():
    s = input("Enter string S: ")
    t = input("Enter string T: ")
    print(min_window(s, t))


if __name__ == '__main__':
    main()

This code works by using a sliding window approach. We maintain two pointers, `l` and `r`, which represent the start and end of the current window. We use a dictionary to track the count of each character in string `T`. 

The sliding window moves from left to right, and at each step, if the current window contains all characters of `T`, we check if the current window's length is smaller than the minimum length found so far. If so, we update the minimum length and the minimum window string. If the current window contains all characters of `T`, we move the left pointer to the right.

The `main` function is used to handle the input for string `S` and string `T`, and then call the `min_window` function to print out the smallest window with all characters of `T`.