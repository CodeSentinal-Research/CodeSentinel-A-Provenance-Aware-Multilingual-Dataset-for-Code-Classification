import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        vehicles = []
        idx = 1
        for _ in range(n):
            vehicles.append((tokens[idx], int(tokens[idx+1])))
            idx += 2
        min_year = int(tokens[idx])
        for v, yr in vehicles:
            if yr > min_year:
                print(v)
if __name__ == '__main__':
    main()