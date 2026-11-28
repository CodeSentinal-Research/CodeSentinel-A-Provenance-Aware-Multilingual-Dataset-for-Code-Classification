import sys
def main():
    lines = sys.stdin.read().strip().split('\n')
    if lines:
        t1 = list(map(int, lines[0].split()))
        t2 = list(map(int, lines[1].split())) if len(lines) > 1 else []
        # If first token is size, or direct array
        l1 = t1[1:] if len(t1) > 0 and len(t1) - 1 == t1[0] else t1
        l2 = t2[1:] if len(t2) > 0 and len(t2) - 1 == t2[0] else t2
        carry = 0
        res = []
        i, j = 0, 0
        while i < len(l1) or j < len(l2) or carry:
            v1 = l1[i] if i < len(l1) else 0
            v2 = l2[j] if j < len(l2) else 0
            s = v1 + v2 + carry
            res.append(s % 10)
            carry = s // 10
            i += 1
            j += 1
        print(*res)
if __name__ == '__main__':
    main()