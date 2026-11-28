# problem title : Add Two Numbers II
# Solve the stated task using standard input and standard output.
import sys
def main():
    lines = sys.stdin.read().strip().split('\n')
    if lines:
        t1 = list(map(int, lines[0].split()))
        t2 = list(map(int, lines[1].split())) if len(lines) > 1 else []
        l1 = t1[1:] if len(t1) > 0 and len(t1) - 1 == t1[0] else t1
        l2 = t2[1:] if len(t2) > 0 and len(t2) - 1 == t2[0] else t2
        s1 = int("".join(map(str, l1))) if l1 else 0
        s2 = int("".join(map(str, l2))) if l2 else 0
        ans = str(s1 + s2)
        print(" ".join(ans))
if __name__ == '__main__':
    main()
