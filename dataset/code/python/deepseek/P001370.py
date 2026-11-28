def max_number(s, k):
    s = list(s)
    s.sort(reverse=True)

    for i in range(len(s)):
        if i + 1 < len(s) and s[i] < s[i + 1] and k > 0:
            s[i], s[i + 1] = s[i + 1], s[i]
            k -= 1

    return ''.join(s)


def main():
    s = input().strip()
    k = int(input().strip())

    print(max_number(s, k))


main()