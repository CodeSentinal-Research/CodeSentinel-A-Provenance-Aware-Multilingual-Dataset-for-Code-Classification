import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        orders = []
        idx = 1
        for _ in range(n):
            oid = tokens[idx]
            status = tokens[idx+1]
            orders.append((oid, status))
            idx += 2
        target_status = tokens[idx]
        for oid, status in orders:
            if status == target_status:
                print(oid)

if __name__ == '__main__':
    main()