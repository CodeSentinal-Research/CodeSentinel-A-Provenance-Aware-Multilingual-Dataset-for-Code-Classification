import sys
def main():
    s = sys.stdin.read().strip()
    if s:
        n = len(s)
        r_q = [i for i, c in enumerate(s) if c == 'R']
        d_q = [i for i, c in enumerate(s) if c == 'D']
        while r_q and d_q:
            r_idx = r_q.pop(0)
            d_idx = d_q.pop(0)
            if r_idx < d_idx:
                r_q.append(r_idx + n)
            else:
                d_q.append(d_idx + n)
        print("Radiant" if r_q else "Dire")
if __name__ == '__main__':
    main()