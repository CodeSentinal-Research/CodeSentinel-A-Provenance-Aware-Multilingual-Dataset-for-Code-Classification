import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + (1 if nums[i] % 2 != 0 else 0)
        q = int(tokens[1+n])
        idx = 2 + n
        for _ in range(q):
            l, r = int(tokens[idx]), int(tokens[idx+1])
            print(pref[r + 1] - pref[l])
            idx += 2
if __name__ == '__main__':
    main()