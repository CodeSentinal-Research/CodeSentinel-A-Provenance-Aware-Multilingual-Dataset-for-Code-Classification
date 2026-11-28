import sys

def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        students = []
        idx = 1
        for _ in range(n):
            name = tokens[idx]
            gpa = float(tokens[idx+1])
            students.append((name, gpa))
            idx += 2
        threshold = float(tokens[idx])
        for name, gpa in students:
            if gpa >= threshold:
                print(name)

if __name__ == '__main__':
    main()