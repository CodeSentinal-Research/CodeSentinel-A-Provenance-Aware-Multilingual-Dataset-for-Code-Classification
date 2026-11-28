import sys
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        employees = []
        idx = 1
        for _ in range(n):
            employees.append((tokens[idx], tokens[idx+1]))
            idx += 2
        date_thresh = tokens[idx]
        for name, d in employees:
            if d < date_thresh:
                print(name)
if __name__ == '__main__':
    main()