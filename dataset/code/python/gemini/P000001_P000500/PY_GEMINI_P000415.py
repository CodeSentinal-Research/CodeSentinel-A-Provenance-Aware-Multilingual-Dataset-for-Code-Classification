import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        patients = []
        idx = 1
        for _ in range(n):
            patients.append((tokens[idx], tokens[idx+1]))
            idx += 2
        blood = tokens[idx]
        for p, bg in patients:
            if bg == blood:
                print(p)
if __name__ == '__main__':
    main()