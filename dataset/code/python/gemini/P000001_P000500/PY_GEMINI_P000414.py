import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        flights = []
        idx = 1
        for _ in range(n):
            flights.append((tokens[idx], float(tokens[idx+1]), tokens[idx+2]))
            idx += 3
        budget = float(tokens[idx])
        for f, price, status in flights:
            if price <= budget and status.lower() in ("available", "true", "1", "yes"):
                print(f)
if __name__ == '__main__':
    main()