def prefix_char_values(s: str) -> list:
    res = []
    cur = 0
    for c in s:
        cur += ord(c) - 96
        res.append(cur)
    return res

if __name__ == '__main__':
    s = input().strip()
    print(*prefix_char_values(s))