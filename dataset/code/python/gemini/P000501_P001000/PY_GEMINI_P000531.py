import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        calls = list(map(int, tokens[1:1+n]))
        q = []
        for t in calls:
            q.append(t)
            while q and q[0] < t - 3000:
                q.pop(0)
            print(len(q))
if __name__ == '__main__':
    main()