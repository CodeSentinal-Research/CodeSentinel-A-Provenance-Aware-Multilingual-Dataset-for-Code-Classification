import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        deck = sorted(list(map(int, tokens[1:1+n])))
        q = list(range(n))
        res = [0] * n
        for card in deck:
            res[q.pop(0)] = card
            if q:
                q.append(q.pop(0))
        print(*res)
if __name__ == '__main__':
    main()