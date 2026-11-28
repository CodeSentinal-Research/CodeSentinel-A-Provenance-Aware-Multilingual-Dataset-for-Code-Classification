import sys

def is_isomorphic(s: str, t: str) -> bool:
    if len(s) != len(t): return False
    map_st, map_ts = {}, {}
    for c1, c2 in zip(s, t):
        if (c1 in map_st and map_st[c1] != c2) or (c2 in map_ts and map_ts[c2] != c1):
            return False
        map_st[c1] = c2
        map_ts[c2] = c1
    return True

def main():
    lines = sys.stdin.read().split()
    if len(lines) >= 2:
        print("Yes" if is_isomorphic(lines[0], lines[1]) else "No")

if __name__ == '__main__':
    main()