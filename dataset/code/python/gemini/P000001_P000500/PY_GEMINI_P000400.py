import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        employees = []
        idx = 1
        for _ in range(n):
            name = tokens[idx]
            salary = float(tokens[idx+1])
            employees.append((name, salary))
            idx += 2
        min_sal = float(tokens[idx])
        max_sal = float(tokens[idx+1])
        for name, sal in employees:
            if min_sal <= sal <= max_sal:
                print(name)

if __name__ == '__main__':
    main()