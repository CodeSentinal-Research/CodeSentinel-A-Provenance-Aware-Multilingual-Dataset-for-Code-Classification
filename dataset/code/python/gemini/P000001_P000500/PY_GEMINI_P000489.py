import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        q = int(tokens[0])
        idx = 1
        st = []
        min_st = []
        for _ in range(q):
            cmd = tokens[idx]
            if cmd == "push":
                val = int(tokens[idx+1])
                st.append(val)
                min_st.append(min(val, min_st[-1] if min_st else val))
                idx += 2
            elif cmd == "pop":
                if st:
                    st.pop()
                    min_st.pop()
                idx += 1
            elif cmd == "top":
                if st: print(st[-1])
                idx += 1
            elif cmd == "getMin":
                if min_st: print(min_st[-1])
                idx += 1
if __name__ == '__main__':
    main()