# problem title : Clear Digits from String
# Solve the stated task using standard input and standard output.
import sys
def main():
    s = sys.stdin.read().strip()
    st = []
    for c in s:
        if c.isdigit():
            if st: st.pop()
        else:
            st.append(c)
    print("".join(st))
if __name__ == '__main__':
    main()
