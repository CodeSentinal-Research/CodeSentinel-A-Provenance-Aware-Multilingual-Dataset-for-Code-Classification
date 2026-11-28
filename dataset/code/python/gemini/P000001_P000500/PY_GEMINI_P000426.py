import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        rests = []
        idx = 1
        for _ in range(n):
            rests.append((tokens[idx], float(tokens[idx+1])))
            idx += 2
        threshold = float(tokens[idx])
        for r, rating in rests:
            if rating >= threshold:
                print(r)
if __name__ == '__main__':
    main()