import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        doctors = []
        idx = 1
        for _ in range(n):
            doctors.append((tokens[idx], tokens[idx+1]))
            idx += 2
        spec = tokens[idx]
        for d, s in doctors:
            if s == spec:
                print(d)
if __name__ == '__main__':
    main()