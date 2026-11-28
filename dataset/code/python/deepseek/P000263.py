def last_non_repeating_char(s):
    last_occurrence = {}
    for i, c in enumerate(s):
        last_occurrence[c] = i
    for c in s[::-1]:
        if last_occurrence[c] == s.index(c):
            return c
    return -1

if __name__ == "__main__":
    s = input()
    print(last_non_repeating_char(s))