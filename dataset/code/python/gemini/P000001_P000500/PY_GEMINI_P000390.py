import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        products = []
        idx = 1
        for _ in range(n):
            pname = tokens[idx]
            price = float(tokens[idx+1])
            products.append((pname, price))
            idx += 2
        min_p = float(tokens[idx])
        max_p = float(tokens[idx+1])
        matches = [pname for pname, price in products if min_p <= price <= max_p]
        for m in matches:
            print(m)

if __name__ == '__main__':
    main()