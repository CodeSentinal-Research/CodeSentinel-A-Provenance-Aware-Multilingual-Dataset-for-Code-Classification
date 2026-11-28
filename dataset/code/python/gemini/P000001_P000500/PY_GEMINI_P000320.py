import sys

def shortest_to_char(s: str, c: str):
    n = len(s)
    res = [float('inf')] * n
    prev = -float('inf')
    for i in range(n):
        if s[i] == c: prev = i
        res[i] = i - prev
    prev = float('inf')
    for i in range(n - 1, -1, -1):
        if s[i] == c: prev = i
        res[i] = min(res[i], prev - i)
    return res

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print(" ".join(map(str, shortest_to_char(lines[0], lines[1]))))

if __name__ == '__main__':
    main()