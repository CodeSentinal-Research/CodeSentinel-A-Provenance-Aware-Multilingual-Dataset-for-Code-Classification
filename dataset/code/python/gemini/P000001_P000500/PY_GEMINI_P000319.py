import sys

def is_one_edit_distance(s: str, t: str) -> bool:
    if abs(len(s) - len(t)) > 1 or s == t: return False
    m, n = len(s), len(t)
    for i in range(min(m, n)):
        if s[i] != t[i]:
            if m == n: return s[i+1:] == t[i+1:]
            elif m < n: return s[i:] == t[i+1:]
            else: return s[i+1:] == t[i:]
    return abs(m - n) == 1

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if is_one_edit_distance(lines[0], lines[1]) else "No")
    elif len(lines) == 1:
        print("Yes" if is_one_edit_distance(lines[0], "") else "No")

if __name__ == '__main__':
    main()