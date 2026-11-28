import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        members = []
        idx = 1
        for _ in range(n):
            members.append((tokens[idx], tokens[idx+1]))
            idx += 2
        curr_date = tokens[idx]
        for mid, exp in members:
            if exp < curr_date:
                print(mid)
if __name__ == '__main__':
    main()