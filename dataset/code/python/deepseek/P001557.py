def main():
    s = input()
    k = int(input())
    start, max_length, count = 0, 0, 0
    for i in range(len(s)):
        if s[i] == s[start]:
            count += 1
        else:
            count = 1
        max_length = max(max_length, count)
        if max_length + k - i > count:
            count = max_length
            start = i
    print(max_length)

if __name__ == "__main__":
    main()