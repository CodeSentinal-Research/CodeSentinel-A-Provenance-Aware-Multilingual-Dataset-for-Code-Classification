import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        orders = []
        idx = 1
        for _ in range(n):
            orders.append((tokens[idx], int(tokens[idx+1])))
            idx += 2
        days = int(tokens[idx])
        for oid, d in orders:
            if d > days:
                print(oid)
if __name__ == '__main__':
    main()