import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        products = []
        idx = 1
        for _ in range(n):
            name = tokens[idx]
            stock = int(tokens[idx+1])
            products.append((name, stock))
            idx += 2
        threshold = int(tokens[idx])
        for name, stock in products:
            if stock < threshold:
                print(name)

if __name__ == '__main__':
    main()