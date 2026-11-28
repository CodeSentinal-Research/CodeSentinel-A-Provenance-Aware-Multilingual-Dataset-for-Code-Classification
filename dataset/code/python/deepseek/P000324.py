def repeated_substring_pattern(s):
    size = len(s)
    for length in range(1, size//2+1):
        if size % length == 0:
            substring = s[:length]
            if substring*(size//length) == s:
                return 'Yes'
    return 'No'

def main():
    s = input()
    print(repeated_substring_pattern(s))

if __name__ == "__main__":
    main()