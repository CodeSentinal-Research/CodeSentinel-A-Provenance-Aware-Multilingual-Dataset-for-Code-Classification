import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        prods = []
        idx = 1
        for _ in range(n):
            prods.append((tokens[idx], float(tokens[idx+1])))
            idx += 2
        min_p = float(tokens[idx])
        for p, price in prods:
            if price >= min_p:
                print(p)
if __name__ == '__main__':
    main()