import sys
from collections import Counter
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        nums = list(map(int, tokens[1:1+n]))
        q_count = int(tokens[1+n])
        idx = 2 + n
        count = Counter(nums)
        q = list(nums)
        for _ in range(q_count):
            cmd = tokens[idx]
            if cmd == "showFirstUnique":
                while q and count[q[0]] > 1: q.pop(0)
                print(q[0] if q else -1)
                idx += 1
            elif cmd == "add":
                val = int(tokens[idx+1])
                count[val] += 1
                q.append(val)
                idx += 2
if __name__ == '__main__':
    main()