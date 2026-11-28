# problem title : Design Skip List
# Solve the stated task using standard input and standard output.
import sys
from collections import Counter
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        cnt = Counter()
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "add":
                num = int(tokens[idx+1])
                cnt[num] += 1
                idx += 2
            elif cmd == "search":
                num = int(tokens[idx+1])
                print("true" if cnt[num] > 0 else "false")
                idx += 2
            elif cmd == "erase":
                num = int(tokens[idx+1])
                if cnt[num] > 0:
                    cnt[num] -= 1
                    print("true")
                else:
                    print("false")
                idx += 2
if __name__ == '__main__':
    main()
