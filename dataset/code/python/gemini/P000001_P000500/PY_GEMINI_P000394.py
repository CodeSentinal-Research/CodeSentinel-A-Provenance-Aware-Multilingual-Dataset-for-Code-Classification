import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        products = []
        idx = 1
        for _ in range(n):
            name = tokens[idx]
            brand = tokens[idx+1]
            products.append((name, brand))
            idx += 2
        target_brand = tokens[idx]
        for name, brand in products:
            if brand == target_brand:
                print(name)

if __name__ == '__main__':
    main()