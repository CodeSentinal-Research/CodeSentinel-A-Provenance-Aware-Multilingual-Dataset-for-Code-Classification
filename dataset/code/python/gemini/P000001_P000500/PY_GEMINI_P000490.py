import sys
def process(s):
    st = []
    for c in s:
        if c == '#':
            if st: st.pop()
        else:
            st.append(c)
    return "".join(st)

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        s = tokens[0]
        t = tokens[1] if len(tokens) > 1 else ""
        print("true" if process(s) == process(t) else "false")
if __name__ == '__main__':
    main()