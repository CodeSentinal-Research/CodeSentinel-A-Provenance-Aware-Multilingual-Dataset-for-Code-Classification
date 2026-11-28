def first_non_repeating_char(s):
    count = {}
    for char in s:
        if char in count:
            count[char] += 1
        else:
            count[char] = 1

    for char in s:
        if count[char] == 1:
            return char

    return -1

def main():
    s = input()
    print(first_non_repeating_char(s))

if __name__ == "__main__":
    main()