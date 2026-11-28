import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        s1, s2 = [], []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "push":
                s1.append(int(tokens[idx+1]))
                idx += 2
            elif cmd == "pop":
                if not s2:
                    while s1: s2.append(s1.pop())
                if s2: print(s2.pop())
                idx += 1
            elif cmd == "peek":
                if not s2:
                    while s1: s2.append(s1.pop())
                if s2: print(s2[-1])
                idx += 1
            elif cmd == "empty":
                print("true" if not s1 and not s2 else "false")
                idx += 1
if __name__ == '__main__':
    main()