import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        events = []
        idx = 1
        for _ in range(n):
            events.append((tokens[idx], tokens[idx+1]))
            idx += 2
        date = tokens[idx]
        for e, d in events:
            if d == date:
                print(e)
if __name__ == '__main__':
    main()