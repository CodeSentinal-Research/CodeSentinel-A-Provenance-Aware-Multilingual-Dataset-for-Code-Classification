def count_binary_substrings(s):
    prev = s[0]
    count = 1
    total = 0
    for char in s[1:]:
        if char == prev:
            count += 1
        else:
            total += count
            count = 1
            prev = char
    total += count
    return total

def main():
    s = input()
    print(count_binary_substrings(s))

if __name__ == "__main__":
    main()