import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        st = []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "push":
                st.append(int(tokens[idx+1]))
                idx += 2
            elif cmd == "pop":
                if st: print(st.pop())
                idx += 1
            elif cmd == "top":
                if st: print(st[-1])
                idx += 1
            elif cmd == "empty":
                print("true" if len(st) == 0 else "false")
                idx += 1
if __name__ == '__main__':
    main()