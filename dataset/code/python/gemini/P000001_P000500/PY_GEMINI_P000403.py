import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        trains = []
        idx = 1
        for _ in range(n):
            trains.append((tokens[idx], tokens[idx+1]))
            idx += 2
        station = tokens[idx]
        for t, s in trains:
            if s == station:
                print(t)
if __name__ == '__main__':
    main()